
#include <iostream>
#include <vector>
#include "State.cpp"
#include <string>
#ifndef SOLUTION_CPP
#define SOLUTION_CPP


#define RED "\033[31m"
#define RESET "\033[0m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define MAGENTA "\033[35m"
#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"
#define BLINK "\033[5m"
#define REVERCE "\033[7m"
#define HIDE "\033[8m"
#define CLEAR "\033[2J"
#define CLRLINE "\r\033[K"
template <class T>
class Solution
{
public:
    Solution() : m_solution({}) {}
    Solution(const Solution<T> &other)
    {
        for (State<T> *statePtr : other.m_solution)
        {
            State<T> *newState = new State<T>(*statePtr); // Dereference the pointer and create a new State
            m_solution.push_back(newState);               // Push the address of the new State to the vector
        }
        this->message = other.message;
        this->numOfNodes = other.numOfNodes;
        this->cost = other.cost;
        this->numOfEvaluatedNodes = other.numOfEvaluatedNodes;
        this->time = other.time;
    }
    Solution<T> &operator=(const Solution<T> &other)
    {
        if (this == &other)
        {
            return *this;
        }
        // Clean up the solution vector if needed
        for (State<T> *state : m_solution)
        {
            delete state;
        }
        m_solution.clear();
        for (State<T> *statePtr : other.m_solution)
        {
            State<T> newState(*statePtr); // Dereference the pointer and create a new State
            m_solution.push_back(&newState);
        }
        this->message = other.message;
        this->numOfNodes = other.numOfNodes;
        this->cost = other.cost;
        this->numOfEvaluatedNodes = other.numOfEvaluatedNodes;
        this->time = other.time;
        return *this;
    }
    ~Solution()
    {
        // Clean up the solution vector if needed
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
        cout <<BOLD<<MAGENTA<< "---------" << endl;
        cout << "Solution:" << endl;
        cout << "---------" << endl;
        cout << "---------" << endl;
        cout << "Message: " << endl;
        if (this->message == "")
        {
            cout <<BOLD<<RED<< "No message" <<RESET<< endl;
        }
        if (this->message.compare("Path from start to goal:") == 0)
        {
            cout <<GREEN<< "Path from start to goal:" <<RESET<< endl;
        }
        else {
            cout <<BOLD<<RED<< "No path from start to goal" <<RESET<< endl;
        }
        
        cout << "---------" << endl;
        for (State<T> *state : m_solution)
        {
            state->printState();
        }
        cout <<MAGENTA<< "Cost: " <<WHITE << this->cost << endl;
        cout <<MAGENTA<< "Number of nodes: " <<WHITE << this->numOfNodes << endl;
        cout <<MAGENTA<< "Number of evaluated nodes: " <<WHITE << this->numOfEvaluatedNodes << endl;
        cout <<MAGENTA<< "time took to solve: " << WHITE<<this->time <<RESET<< endl;
    }
    void setTime(double time)
    {
        this->time = time;
    }
    double getTime()
    {
        return this->time;
    }

private:
    std::vector<State<T> *> m_solution;
    string message;
    int numOfNodes;
    int cost;
    int numOfEvaluatedNodes;
    double time;
};

#endif // SOLUTION_CPP

