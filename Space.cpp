//
//  Space.cpp
//  spacial
//
//  Created by Yiru on 08/01/2014.
//  Copyright (c) 2014 Yiru. All rights reserved.
//
#include "Space.hpp"
	
//Initialize les aliens
void Space::Init_Alien(){
	for(size_t i = 0; i<ALIEN_N; ++i)
	{
		_AlienList.push_back(Alien(i,0,ALIEN_WIDTH,ALIEN_HEIGHT));///////
	}
}
void Space::apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination){
    //Holds offsets
	SDL_Rect* clip = NULL ;
    SDL_Rect offset;
    
    //Get offsets
    offset.x = x;
    offset.y = y;
    
    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}

SDL_Surface * Space::load_image( std::string filename ){
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;
    
    //The optimized surface that will be used
    SDL_Surface* optimizedImage = NULL;
    
    //Load the image
    loadedImage = IMG_Load( filename.c_str() );
    
    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized surface
        optimizedImage = SDL_DisplayFormat( loadedImage );
        
        //Free the old surface
        SDL_FreeSurface( loadedImage );
        
        //If the surface was optimized
        if( optimizedImage != NULL )
        {
            //Color key surface
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0xFF, 0xFF, 0xFF ) );
        }
    }
    
    //Return the optimized surface
    return optimizedImage;
}



bool Space::init(){
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }
    
    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
    
    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return false;
    }
	if( TTF_Init() == -1 )
	{
	        return false;
	}
    //Set the window caption
    SDL_WM_SetCaption( "Conquête Spaciale", NULL );
	
	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
	   {
	      printf("%s", Mix_GetError());
	   }
	   Mix_VolumeMusic(MIX_MAX_VOLUME / 2); //Mettre le volume à la moitié
 	
	/*//Initialisze SDL_ttf
    if( TTF_Init() == -1 )
    {
        return false;    
    }
    
    //Initialize SDL_mixer
    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        return false;    
    }
	*/
    //If everything initialized fine
    return true;
}

bool Space::load_files(){
    //Load the dot image
    dot = load_image( "images/dot.png" );
    
    //Load the background
    background = load_image( "images/space.jpg" );
	
	//Load the missile
	missile = load_image("images/missile1.png");
    
	//Load the laser
	laser = load_image("images/laser.png");
	//Load the alien
	alien = load_image("images/enemie1.jpg");
	//load the alien missile
	alien_bullet = load_image("images/bullet1.png");
	//load the explosion
	explosion = load_image("images/explosion.jpg");
	//Chargement de la musique
	musique = Mix_LoadMUS("musique.mp3"); 
    //If there was a problem in loading the dot
    if( dot == NULL )
    {
        return false;
    }
    if( background == NULL )
    {
        return false;
    }
    if( missile == NULL )
    {
        return false;
    }
    if( alien == NULL )
    {
        return false;
    }
    if( laser == NULL )
    {
		//std::cout<<"out"<<std::endl;
        return false;
    }
    if( alien_bullet == NULL )
    {
        return false;
		//std::cout<<"faut";
    }
	if(explosion == NULL)
		return false;
    //If everything loaded fine
    return true;
}
/*
bool load_files(SDL_Surface *SF,std::string filename)
{
    //Load the dot image
	SF = load_image(filename);
	if (SF == NULL)
		{return false;}
    //If everything loaded fine
    return true;
}*/

void Space::clean_up(){
    //Free the surfaces
    SDL_FreeSurface( dot );
    SDL_FreeSurface( background );
	SDL_FreeSurface( laser );
	SDL_FreeSurface( alien );
	SDL_FreeSurface( missile);
    SDL_FreeSurface(alien_bullet);
	SDL_FreeSurface(information1);
	SDL_FreeSurface(information2);
	SDL_FreeSurface(information3);
	SDL_FreeSurface(information4);
	TTF_CloseFont( font );
	//Quit SDL_ttf
	TTF_Quit();
	Mix_FreeMusic(musique); //Libération de la musique
	
	Mix_CloseAudio(); //Fermeture de l'API
	//Quit SDL
    //SDL_Quit();
}

void Space::MoveAllObject(){
	myHero.Move();
        //Move the missiles of the Hero
		for(std::vector<Missile>::size_type i = 0; i < myHero._MissileList.size(); ++i) {
			myHero._MissileList[i].Move();
			if(myHero._MissileList[i].TestOut(SCREEN_WIDTH-50) == true){
				
				myHero._MissileList[i].setUnvisible();
			}
			
		}
		//Deplace les aliens et ses missiles
		for(std::vector<Alien>::size_type i = 0; i < _AlienList.size(); ++i)
		{
			if(_AlienList[i].getOutFlag()==true){
				srand (time(NULL));
				//_AlienList[i].setY(radom);
				_AlienList[i].setX(SCREEN_WIDTH-40);
				_AlienList[i].setY(i*50+rand()%40);
				_AlienList[i].setVisible();
				_AlienList[i].setOutFlag(false);
				
			}
			//else{ 				
			for(std::vector<Missile>::size_type j = 0;j < _AlienList[i]._MissileList.size();j++){
	
				if(_AlienList[i]._MissileList[j].getVisible()==false){	
					if(_AlienList[i].getVisible()){					
						srand (time(NULL));								
						if (( rand()%10) == i){
							_AlienList[i].LanceMissile();
						}							
					}
				}
				//Missiles d'alien se deplace					
				_AlienList[i]._MissileList[j].Move();
				if(_AlienList[i]._MissileList[j].TestOut(SCREEN_WIDTH)==true)
					_AlienList[i]._MissileList[j].setUnvisible();
				
			}
			if(_AlienList[i].TestOut(5)){
				_AlienList[i].setUnvisible();
				//std::cout<<_AlienList[i].getOutFlag()<<std::endl;
				_AlienList[i].setX(SCREEN_WIDTH-40);
			}
				//}
			if(rand()%5 == 0)
				_AlienList[i].setYVel(-_AlienList[i].getYVel());
			_AlienList[i].Move();
		}
}

void Space::TestCollision(Hero& hero){
	hero.CollisionAlien(_AlienList);
	hero.AttaquerAlien(_AlienList);
	hero.LaserAlien(_AlienList);
	
}

void Space::ShowAllObject(){
	//show the hero
	if(myHero.getVisible()  == true)
		myHero.ObjectShow(dot,screen);
	
	///show the missiles of the hero
	for(std::vector<Missile>::size_type i = 0; i < myHero._MissileList.size(); ++i) {
		if (myHero._MissileList[i].getVisible()== true){
			
			myHero._MissileList[i].ObjectShow(missile,screen);
		}
	}
    //Show the laser
	if(myHero._laser.getVisible()== true)
		myHero._laser.ObjectShow(laser,screen);
    //Affiche les aliens et ses bullets
	for(std::vector<Alien>::size_type i = 0; i < _AlienList.size(); ++i){
		for(std::vector<Missile>::size_type j = 0;j < _AlienList[i]._MissileList.size();j ++){
			if(_AlienList[i]._MissileList[j].getVisible()==true){
				_AlienList[i]._MissileList[j].ObjectShow(alien_bullet,screen);
			}
		}
		if (_AlienList[i].getVisible()){
			
			_AlienList[i].ObjectShow(alien,screen);
		}
	}
}
void Space::RecordScore(int score,std::string name){
	std::ofstream ofs("record.dat");
	assert(ofs.good());
	ofs<<score<<name<<std::endl;
	ofs.close();
	
}
void Space::ReadScore(std::string filename){
	std::ifstream ifs(filename.c_str());
	int score;
	std::string name;
	ifs>>score>>name;
	std::cout<<score<<name<<std::endl;
	ifs.close();
	
}
std::string Space::itos(int i) {
    std::stringstream s;
    s << i;
    return s.str();
}
void Space::ShowInformation(Hero myHero,SDL_Surface * screen){
	
	std::string PlayInfo = "Info";
	std::string s1 = "Vie: ";
	std::string s2 = "Score: ";
	int myvie =myHero.getVie();
	int myscore = myHero.getScore();
	std::string s3 = itos(myvie);
	std::string s4 = itos(myscore);
	//std::stringstream oss;
	
	information1 = TTF_RenderText_Solid( font, s1.c_str(), textColor );
	information2 = TTF_RenderText_Solid( font, s2.c_str(), textColor );
	information3 = TTF_RenderText_Solid( font, s3.c_str(), textColor );
	information4 = TTF_RenderText_Solid( font, s4.c_str(), textColor );
	apply_surface( 10, 10 , information1, screen );
	apply_surface( 10, 25 , information2, screen );
	apply_surface( 90, 10 , information3, screen );
	apply_surface( 90, 25 , information4, screen );
	
}
/*accesseur*/
Hero Space::getHero(){
	return myHero;
}
void Space::ResetGame(){
	myHero.setVie(10);
	myHero.setX(10);
	myHero.setY(SCREEN_HEIGHT/2);
	myHero.setVisible();
	myHero.setXVel(0);
	myHero.setYVel(0);
	while(_AlienList.size()>0){
		_AlienList.pop_back();
	}
	Init_Alien();
	
}
int Space::Battle()
{   
    //Quit flag et mort flag
	bool quit = false;  
	bool death = false;  
    //The offsets of the background
    int bgX = 0, bgY = 0;
    Init_Alien();       
    //Initialize
    if( init() == false ){
        return 1;
    }    
    //Load the files
    if( load_files() == false ){
        return 1;
    }
	
	//load the font
	font = NULL;
	textColor.r = 0xFF;
	textColor.g = 0xFF;
	textColor.b = 0xFF;
	font = TTF_OpenFont( "images/lazy.ttf", 18);
	if (font == NULL)
		std::cout<<"null";
	
	ResetGame();
	Mix_HaltMusic();
	Mix_PlayMusic(musique, 1);
    //While the user hasn't quit
	while((quit == false)&&(death == false)){
        //Start the frame timer
        fps.start();
        
        //While there's events to handle
        while( SDL_PollEvent( &myHero.event ) ){
        	//Handle events for the dot
            myHero.handle_input(fps);
            //If the user has quit the window
            if( myHero.event.type == SDL_QUIT ){
            	//Quit the program
               	quit = true;
			}
		}
        //Deplace tout les objets
		MoveAllObject();
		
		//Test the laser time
		myHero._laser.TestTime(fps.get_ticks());
		
		//Test les collision
		TestCollision(myHero);
		//Test si le hero est mort
		if (myHero.getVie()<= 0){
			death = true;
			//RecordScore(myHero.getScore());
			//std::cout<<death<<std::endl;
		}
       	//Scroll background
       	bgX -= 2;
        
       	//If the background has gone too far
       	if( bgX <= -background->w ){
       		//Reset the offset
			bgX = 0;
    	}
        
        //Show the background
        apply_surface( bgX, bgY, background, screen );
        apply_surface( bgX + background->w, bgY, background, screen );		
		ShowAllObject();
		ShowInformation(myHero,screen);
		//information = TTF_RenderText_Solid( font, "PlayInfo", textColor );
		//apply_surface( 10, 10 , information, screen );
        //Update the screen
        if( SDL_Flip( screen ) == -1 ){
		return 1;
        }
        
 		//Cap the frame rate
        if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND ){
		SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
       	}
	 }
	 //dès que le hero est mort
	 //RecordScore();
	 //Clean up
	 //ReadScore("record.dat");
	 clean_up(); 
	 if((quit==true)&&(death == false))
	 	return 1;
	 else if ((quit == false)&&(death == true))
		 return 2;
	 else if((quit==true)&&(death == true))
		 return 3;
	 else
		 return 0;
		
   
    
} 