#pragma once
#include "Controller/SolveMazeCommand.h"
#include "Controller/GenrateMazeCommand.h"
#include "Controller/CompressMazeCommand.h"
#include "Controller/DecompressMazeCommand.h"
#include "Controller/MazeSizeCommand.h"
#include <unordered_map>
#include "Model.h"
#include "View.h"
#include "View/CLI.h"  // Include the CLI header

class MazeController {
public:
    MazeController();

    void start();

private:
    MazeModel* model_;
    MazeView* view_;
    CLI* cli_;  // Include the CLI instance

    // void handleGenerateCommand();
    // void handleSolveCommand();
    // Add other command handling methods as needed
};
