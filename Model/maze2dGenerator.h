#pragma once

#include <ctime>
#include <string>
#include "maze2d.h"

class Maze2dGenerator {
public:
    virtual Maze2d generate(int rows=5, int cols=5) = 0;
    std::string measureAlgorithmTime();
};
