#pragma once
#include <iostream>
#include <vector>
#include <memory> // Include the necessary header for unique_ptr
#include "State.h" // Include the State class header

template <class T>
class Solution
{
public:
	Solution() {};
	~Solution() {};

private:
	std::vector<unique_ptr<State<T>>> m_solution;
};

