CC = g++
CFLAGS = -g -std=c++17

INCLUDES = -I.

OBJS = main.o maze2d.o maze2dGenerator.o Maze2dSearchable.o SimpleMaze2dGenerator.o mazeAdapter.o demo.o mazeCompression.o command.o CLI.o SolveMazeCommand.o BFS.o State.o Solution.o CommonSearcher.o GenrateMazeCommand.o View.o Model.o Controller.o CompressMazeCommand.o DecompressMazeCommand.o MazeSizeCommand.o DisplayMazeCommand.o MazeMatrixSizeCommand.o ShowDirCommand.o solveFromFile.o   # Add other object files for other classes if present

main: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o main

main.o: Controller/main.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c Controller/main.cpp

maze2d.o: Model/maze2d.cpp Model/maze2d.h 
	$(CC) $(CFLAGS) $(INCLUDES) -c Model/maze2d.cpp

maze2dGenerator.o: Model/maze2dGenerator.cpp  Model/maze2dGenerator.h
	$(CC) $(CFLAGS) $(INCLUDES) -c Model/maze2dGenerator.cpp
Maze2dSearchable.o: Model/Maze2dSearchable.cpp Model/Maze2dSearchable.h
	$(CC) $(CFLAGS) $(INCLUDES) -c Model/Maze2dSearchable.cpp
SimpleMaze2dGenerator.o: Model/SimpleMaze2dGenerator.cpp Model/SimpleMaze2dGenerator.h
	$(CC) $(CFLAGS) $(INCLUDES) -c Model/SimpleMaze2dGenerator.cpp
mazeAdapter.o: Model/mazeAdapter.h Model/mazeAdapter.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c Model/mazeAdapter.cpp
demo.o: View/demo.h View/demo.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c View/demo.cpp
mazeCompression.o: Model/mazeCompression.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c Model/mazeCompression.cpp
command.o: Controller/command.cpp 
	$(CC) $(CFLAGS) $(INCLUDES) -c Controller/command.cpp
CLI.o: View/CLI.cpp View/CLI.h
	$(CC) $(CFLAGS) $(INCLUDES) -c View/CLI.cpp 
SolveMazeCommand.o: Controller/SolveMazeCommand.cpp Controller/SolveMazeCommand.h
	$(CC) $(CFLAGS) $(INCLUDES) -c Controller/SolveMazeCommand.cpp
BFS.o: Model/BFS.cpp 
	$(CC) $(CFLAGS) $(INCLUDES) -c Model/BFS.cpp
State.o:  Model/State.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c Model/State.cpp
Solution.o:  Model/Solution.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c Model/Solution.cpp
CommonSearcher.o:  Model/CommonSearcher.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c Model/CommonSearcher.cpp
GenrateMazeCommand.o: Controller/GenrateMazeCommand.cpp Controller/GenrateMazeCommand.h
	$(CC) $(CFLAGS) $(INCLUDES) -c Controller/GenrateMazeCommand.cpp
CompressMazeCommand.o: Controller/CompressMazeCommand.cpp Controller/CompressMazeCommand.h
	$(CC) $(CFLAGS) $(INCLUDES) -c Controller/CompressMazeCommand.cpp
DecompressMazeCommand.o: Controller/DecompressMazeCommand.cpp Controller/DecompressMazeCommand.h
	$(CC) $(CFLAGS) $(INCLUDES) -c Controller/DecompressMazeCommand.cpp
MazeSizeCommand.o: Controller/MazeSizeCommand.cpp Controller/MazeSizeCommand.h
	$(CC) $(CFLAGS) $(INCLUDES) -c Controller/MazeSizeCommand.cpp
DisplayMazeCommand.o: Controller/DisplayMazeCommand.cpp Controller/DisplayMazeCommand.h
	$(CC) $(CFLAGS) $(INCLUDES) -c Controller/DisplayMazeCommand.cpp
MazeMatrixSizeCommand.o: Controller/MazeMatrixSizeCommand.cpp Controller/MazeMatrixSizeCommand.h
	$(CC) $(CFLAGS) $(INCLUDES) -c Controller/MazeMatrixSizeCommand.cpp
ShowDirCommand.o: Controller/ShowDirCommand.cpp Controller/ShowDirCommand.h
	$(CC) $(CFLAGS) $(INCLUDES) -c Controller/ShowDirCommand.cpp
solveFromFile.o: Controller/solveFromFile.cpp Controller/solveFromFile.h
	$(CC) $(CFLAGS) $(INCLUDES) -c Controller/solveFromFile.cpp
Controller.o: Controller.h Controller.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c Controller.cpp
Model.o: Model.h Model.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c Model.cpp
View.o: View.h View.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c View.cpp

run: main
	./main

clean:
	rm -f $(OBJS) main
