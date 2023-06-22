#ifndef WALL_HPP
#define WALL_HPP
#include <iostream>
#include "mapSite.hpp"

class Wall : public MapSite {
public:
    void enter() override {
        std::cout << "You hit a wall." << std::endl;
    }
};

#endif
