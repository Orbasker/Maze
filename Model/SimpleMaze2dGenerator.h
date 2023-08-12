#pragma once

#include "maze2dGenerator.h"

class SimpleMaze2dGenerator : public Maze2dGenerator {
public:
    SimpleMaze2dGenerator();
    virtual Maze2d generate(int rows, int cols) override;
    friend ostream& operator<<(ostream& os, const SimpleMaze2dGenerator& mg);
    Maze2d getMaze() const;
    void setMaze(const Maze2d& maze);
    SimpleMaze2dGenerator& operator=(const SimpleMaze2dGenerator& mg);

private:
   Maze2d _maze;
};
