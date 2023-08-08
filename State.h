#pragma once

#include <string>
#include <memory>
using namespace std;

template <class T>
class State
{
public:
	State(T& state): m_state(state), m_cost(0), m_cameFrom(nullptr){}
	State(const std::pair<int, int>& state) : m_state(state), m_cost(0), m_cameFrom(nullptr) {}
	~State() {};
	bool operator==(const State& s) const { return m_state == s.m_state; }
	T& getState() { return m_state; }
	State<std::pair<int, int>>* getStartState()  {
    // Return the starting state of the maze (e.g., (0, 0))
    return new State<std::pair<int, int>>(std::make_pair(0, 0));
	}

	State<std::pair<int, int>>* getGoalState(const T& maze_)  {
    // Return the goal state of the maze (e.g., (n-1, m-1))
    int n = maze_.getRows();
    int m = maze_.getCols();
	    return new State<std::pair<int, int>>(std::make_pair(n - 1, m - 1));
}


private:
	//string				m_state;
	T					m_state;
	double				m_cost;
	unique_ptr<State>	m_cameFrom;
};

