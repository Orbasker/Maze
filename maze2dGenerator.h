#pragma once

#include <ctime>
#include <string>
#include "maze2d.h"

class Maze2dGenerator {
public:
    virtual Maze2d generate() = 0;
    std::string measureAlgorithmTime();
};
