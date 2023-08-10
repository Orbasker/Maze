CC = g++
CFLAGS = -g -std=c++11

INCLUDES = -I.

OBJS = main.o maze2d.o maze2dGenerator.o Maze2dSearchable.o SimpleMaze2dGenerator.o mazeAdapter.o demo.o mazeCompression.o command.o CLI.o SolveMazeCommand.o BFS.o State.o Solution.o CommonSearcher.o # Add other object files for other classes if present

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
mazeAdapter.o: mazeAdapter.h mazeAdapter.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c mazeAdapter.cpp
demo.o: demo.h demo.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c demo.cpp
mazeCompression.o: mazeCompression.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c mazeCompression.cpp
command.o: command.cpp 
	$(CC) $(CFLAGS) $(INCLUDES) -c command.cpp
CLI.o: CLI.cpp CLI.h
	$(CC) $(CFLAGS) $(INCLUDES) -c CLI.cpp 
SolveMazeCommand.o: SolveMazeCommand.cpp SolveMazeCommand.h
	$(CC) $(CFLAGS) $(INCLUDES) -c SolveMazeCommand.cpp
BFS.o: BFS.cpp BFS.h
	$(CC) $(CFLAGS) $(INCLUDES) -c BFS.cpp
State.o:  State.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c State.cpp
Solution.o:  Solution.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c Solution.cpp
CommonSearcher.o:  CommonSearcher.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c CommonSearcher.cpp


# Add compilation rules for other classes if present
# For example:
# Searchable.o: Searchable.cpp Searchable.h
#	$(CC) $(CFLAGS) $(INCLUDES) -c Searchable.cpp

run: main
	./main

clean:
	rm -f $(OBJS) main
