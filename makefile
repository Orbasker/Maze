CC = g++
CFLAGS = -g -std=c++11

INCLUDES = -I.

OBJS = main.o maze2d.o maze2dGenerator.o Maze2dSearchable.o SimpleMaze2dGenerator.o # Add other object files for other classes if present

main: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o main

main.o: main.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c main.cpp

maze2d.o: maze2d.cpp maze2d.h 
	$(CC) $(CFLAGS) $(INCLUDES) -c maze2d.cpp

maze2dGenerator.o: maze2dGenerator.cpp  maze2dGenerator.h
	$(CC) $(CFLAGS) $(INCLUDES) -c maze2dGenerator.cpp
Maze2dSearchable.o: Maze2dSearchable.cpp Maze2dSearchable.h
	$(CC) $(CFLAGS) $(INCLUDES) -c Maze2dSearchable.cpp
SimpleMaze2dGenerator.o: SimpleMaze2dGenerator.cpp SimpleMaze2dGenerator.h
	$(CC) $(CFLAGS) $(INCLUDES) -c SimpleMaze2dGenerator.cpp
# BFS.o:  BFS.h
# 	$(CC) $(CFLAGS) $(INCLUDES) -c BFS.h

# CommonSearcher.o:  CommonSearcher.h
# 	$(CC) $(CFLAGS) $(INCLUDES) -c CommonSearcher.h


# Add compilation rules for other classes if present
# For example:
# Searchable.o: Searchable.cpp Searchable.h
#	$(CC) $(CFLAGS) $(INCLUDES) -c Searchable.cpp

run: main
	./main

clean:
	rm -f $(OBJS) main
