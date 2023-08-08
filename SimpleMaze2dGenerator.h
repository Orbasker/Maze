#pragma once

#include "maze2dGenerator.h"

class SimpleMaze2dGenerator : public Maze2dGenerator {
public:
    virtual Maze2d generate() override;
};
