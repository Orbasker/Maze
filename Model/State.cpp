// Or Basker   316388743
// Nave Maymon 318887965

#ifndef STATE_CPP
#define STATE_CPP
#include <string>
#include <memory>
#include <iostream>
using namespace std;

template <class T>
class State
{
public:
    State(T &state) : m_state(state), m_cost(0), m_cameFrom(nullptr), m_visited(false) {}
    State(const std::pair<int, int> &state) : m_state(state), m_cost(0), m_cameFrom(nullptr), m_visited(false) {}
    ~State() {}

    bool operator==(const State &s) const
    {
        return m_state == s.m_state;
    }

    T &getState()
    {
        return m_state;
    }

    State<T> *getStartState()
    {
        return new State<std::pair<int, int> >(std::make_pair(0, 0));
    }
    State(const State &other)
    {
        m_state = other.m_state;
        m_cost = other.m_cost;
        if (other.m_cameFrom)
        {
            m_cameFrom = std::unique_ptr<State>(new State<T>(*other.m_cameFrom));
        }
        m_visited = other.m_visited;
    }
    State &operator=(const State &s)
    {
        if (this == &s)
        {
            return *this;
        }
        m_state = s.m_state;
        m_cost = s.m_cost;
        if (s.m_cameFrom)
        {
            m_cameFrom = std::unique_ptr<State<T> >(*s.m_cameFrom);
        }
        else
        {
            m_cameFrom.reset();
        }
        m_visited = s.m_visited;
        return *this;
    }

    State<T> *getGoalState(const T &maze_)
    {
        int n = maze_.getRows();
        int m = maze_.getCols();
        return new State<std::pair<int, int> >(std::make_pair(n - 1, m - 1));
    }

    void setVisited()
    {
        m_visited = true;
    }

    bool isVisited() const
    {
        return m_visited;
    }

    void setCameFrom(State<T> *s)
    {
        m_cameFrom.reset(s);
    }

    State<T> *getCameFrom() const
    {
        return m_cameFrom.get();
    }
    void printState()
    {
        std::cout << "(" << m_state.first << ", " << m_state.second << ")" << std::endl;
    }

    friend ostream &operator<<(ostream &os, const State &s)
    {
        try
        {

            os << "state: " << s.getState() << std::endl;
            os << "came from: " << s.getCameFrom() << std::endl;
            os << "visited: " << s.isVisited() << std::endl;
            return os;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    friend std::ostream &operator<<(std::ostream &os, const std::pair<int, int> &p)
    {

        os << "(" << p.first << ", " << p.second << ")";
        return os;
    }

private:
    T m_state;
    double m_cost;
    std::unique_ptr<State> m_cameFrom;
    bool m_visited;
};

#endif // STATE_CPP