CC = g++
EXECS = Spacial
LIBS = -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer
INCLUDE = -I/usr/include/SDL
OBJS = Object.o Person.o Hero.o Laser.o Missile.o Alien.o Space.o Timer.o main.o

all: $(EXECS)

.c.o:
	$(CC) -c $(INCLUDE) $(LIBS)

$(EXECS): $(OBJS)
	$(CC) -g -o $(EXECS) $(OBJS) $(LIBS)

clean:
	rm -f *.o a.out $(EXECS) core *~


