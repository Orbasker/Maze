CC = g++
CFLAGS = -g -std=c++11
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

OBJS = mazeGenerator.o mazeGame.o mazeFactory.o maze.o room.o door.o

mazeGenerator: $(OBJS)
	$(CC) $(OBJS) -o mazeGenerator $(LDFLAGS)

mazeGenerator.o: mazeGenerator.cpp
	$(CC) $(CFLAGS) -c mazeGenerator.cpp

mazeGame.o: mazeGame.cpp mazeGame.hpp
	$(CC) $(CFLAGS) -c mazeGame.cpp

mazeFactory.o: mazeFactory.cpp 
	$(CC) $(CFLAGS) -c mazeFactory.cpp

maze.o: maze.cpp maze.hpp
	$(CC) $(CFLAGS) -c maze.cpp

room.o: room.cpp room.hpp
	$(CC) $(CFLAGS) -c room.cpp

door.o: door.cpp door.hpp
	$(CC) $(CFLAGS) -c door.cpp

run: mazeGenerator
	./mazeGenerator

clean:
	rm -f $(OBJS) mazeGenerator
