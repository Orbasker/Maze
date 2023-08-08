#pragma once

#include "maze2dGenerator.h"

std::string Maze2dGenerator::measureAlgorithmTime() {
    std::clock_t start_time = std::clock();
    Maze2d maze = generate();
    std::clock_t end_time = std::clock();
    double time_taken = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    return std::to_string(time_taken) + " seconds";
}
