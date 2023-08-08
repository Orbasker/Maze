#pragma once
#include <iostream>
#include <vector>
#include "State.h" 
class Solution {
public:
    Solution() {}
    ~Solution() {}

    void addState(State<std::pair<int, int>>* state) {
        m_solution.push_back(state);
    }

    const std::vector<State<std::pair<int, int>>*>& getSolution() const {
        return m_solution;
    }

private:
    std::vector<State<std::pair<int, int>>*> m_solution;
};
