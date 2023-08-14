
#include <iostream>
#include <vector>
#include "State.cpp"
#include <string>
#ifndef SOLUTION_CPP
#define SOLUTION_CPP
template <class T>
class Solution
{
public:
    Solution() : m_solution({}) {}
    Solution(const Solution<T> &other)
    {
        for (State<T> *statePtr : other.m_solution)
        {
            State<T> *newState = new State<T>(*statePtr); 
            m_solution.push_back(newState);               
        }
        this->message = other.message;
        this->numOfNodes = other.numOfNodes;
        this->cost = other.cost;
        this->numOfEvaluatedNodes = other.numOfEvaluatedNodes;
    }
    Solution<T> &operator=(const Solution<T> &other)
    {
        if (this == &other)
        {
            return *this;
        }
        for (State<T> *state : m_solution)
        {
            delete state;
        }
        m_solution.clear();
        for (State<T> *statePtr : other.m_solution)
        {
            State<T> newState(*statePtr); 
            m_solution.push_back(&newState);
        }
        this->message = other.message;
        this->numOfNodes = other.numOfNodes;
        this->cost = other.cost;
        this->numOfEvaluatedNodes = other.numOfEvaluatedNodes;
        return *this;
    }
    ~Solution()
    {
        for (State<T> *state : m_solution)
        {
            delete state;
        }
    }

    void addState(State<T> *state)
    {
        m_solution.push_back(state);
    }

    const std::vector<State<T> *> &getSolution() const
    {
        return m_solution;
    }
    void setSolution(std::vector<State<T> *> solution)
    {
        this->m_solution = solution;
    }
    void setMessege(string messege)
    {
        this->message = messege;
    }
    string getMessege()
    {
        return this->message;
    }
    void setNumOfNodes(int num)
    {
        this->numOfNodes = num;
    }
    int getNumOfNodes()
    {
        return this->numOfNodes;
    }
    void setCost(int cost)
    {
        this->cost = cost;
    }
    int getCost()
    {
        return this->cost;
    }
    void setNumOfEvaluatedNodes(int num)
    {
        this->numOfEvaluatedNodes = num;
    }
    int getNumOfEvaluatedNodes()
    {
        return this->numOfEvaluatedNodes;
    }
    void printSolution()
    {
        cout << "---------" << endl;
        cout << "Solution:" << endl;
        cout << "---------" << endl;
        cout << "---------" << endl;
        cout << "Message: " << endl;
        cout << this->message << endl;
        cout << "---------" << endl;
        for (State<T> *state : m_solution)
        {
            state->printState();
        }
        cout << "Cost: " << this->cost << endl;
        cout << "Number of nodes: " << this->numOfNodes << endl;
        cout << "Number of evaluated nodes: " << this->numOfEvaluatedNodes << endl;
    }

private:
    std::vector<State<T> *> m_solution;
    string message;
    int numOfNodes;
    int cost;
    int numOfEvaluatedNodes;
};

#endif // SOLUTION_CPP