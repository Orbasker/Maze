#include "DecompressMazeCommand.h"

#include <iostream>



class SolveFromFileCommand : public DecompressMazeCommand
{
    public:
        SolveFromFileCommand(MazeModel* model,MazeView* view): DecompressMazeCommand(model,view) {}
        virtual void execute() override;
};
