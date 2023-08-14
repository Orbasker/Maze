#pragma once
#include "Controller/SolveMazeCommand.h"
#include "Controller/GenrateMazeCommand.h"
#include "Controller/CompressMazeCommand.h"
#include "Controller/DecompressMazeCommand.h"
#include "Controller/MazeSizeCommand.h"
#include "Controller/mazeMatrixSizeCommand.h"
#include "Controller/DisplayMazeCommand.h"
#include "Controller/ShowDirCommand.h"
#include "Controller/solveFromFile.h"
#include <unordered_map>
#include "Model.h"
#include "View.h"
#include "View/CLI.h"  

class MazeController {
public:
    MazeController();

    void start();

private:
    MazeModel* model_;
    MazeView* view_;
    CLI* cli_;  
};
