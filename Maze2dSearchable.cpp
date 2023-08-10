
#include "Maze2dSearchable.h"
Maze2dSearchable::Maze2dSearchable(const Maze2d& maze) : maze_(maze) {
    setPossibleMoves();
    this->numOfVertics_= maze_.getRows() * maze_.getCols();
    this->visited_ = new bool[numOfVertics_];
}

State<std::pair<int, int>>* Maze2dSearchable::getStartState() {
    return new State<std::pair<int, int>>(std::make_pair(0, 0));
}

State<std::pair<int, int>>* Maze2dSearchable::getGoalState() {
    int n = maze_.getRows();
    int m = maze_.getCols();
    return new State<std::pair<int, int>>(std::make_pair(n - 1, m - 1));
}

std::vector<State<std::pair<int, int>>*> Maze2dSearchable::getAllPossibleStates(State<std::pair<int, int>>& s) {
     std::vector<State<std::pair<int, int>>*> possibleStates;
    int i = s.getState().first;
    int j = s.getState().second;
    int n = maze_.getRows();
    int m = maze_.getCols();

    // Define possible movement directions (up, down, left, right)
    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };

    for (int k = 0; k < 4; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];

        if ((ni >= 0 && ni < n && nj >= 0 && nj < m) && ((maze_.getCell(ni, nj) == 0) || (maze_.getCell(ni, nj) == 3))) {
            // Create a new state with the next position and set the current state as its parent
            State<std::pair<int, int>>* nextState = new State<std::pair<int, int>>(std::make_pair(ni, nj));
            nextState->setCameFrom(&s);
            possibleStates.push_back(nextState);
        }

    }

    return possibleStates;
}

void Maze2dSearchable::setPossibleMoves()
{
    for (int i = 0; i < maze_.getRows(); i++) {
        for (int j = 0; j < maze_.getCols(); j++) {
            if (maze_.getCell(i, j) == 0) {
                possibleMoves_.push_back(std::make_pair(i, j));
            }
        }
    }
}


// ... (previous code)

void Maze2dSearchable::BFS() {
    Solution<std::pair<int, int>>* solution = new Solution<std::pair<int, int>>();
    int count = 0;
    visited_ = new bool[numOfVertics_];
    for (int i = 0; i < numOfVertics_; i++)
        visited_[i] = false;

    std::list<State<std::pair<int, int>>*> queue;
    
    State<std::pair<int, int>>* startState = getStartState();
    visited_[startState->getState().first * maze_.getCols() + startState->getState().second] = true;
    queue.push_back(startState);

    while (!queue.empty()) {
        State<std::pair<int, int>>* currState = queue.front();
        std::pair<int, int> currPos = currState->getState();
        queue.pop_front();
        ++count;
        std::pair<int,int> corrdinates = currState->getState();
        // std::cout << "(" << corrdinates.first << ", " << corrdinates.second << ") ";
        int currValue = maze_.getCell(corrdinates.first, corrdinates.second);
        solution->addState(currState);
        solution->setNumOfNodes(maze_.getRows() * maze_.getCols());

        if (currValue == 3) {
             std::list<std::pair<int, int>> path;
            State<std::pair<int, int>>* currentState = currState;

            while (currentState != nullptr) {
                path.push_front(currentState->getState());
                currentState = currentState->getCameFrom();
            }

            // Print the path
            std::cout << "Path from start to goal:" << std::endl;
            solution->setMessege("Path from start to goal:");
            for (const std::pair<int, int>& pos : path) {
                std::cout << "(" << pos.first << ", " << pos.second << ") ";
                solution->setNumOfEvaluatedNodes(count);
                solution->setCost(solution->getNumOfNodes() - solution->getNumOfEvaluatedNodes());
            }
            std::cout << std::endl;
            this->set_solution(solution);
            break;
            // return solution;
        }

        std::vector<State<std::pair<int, int>>*> possibleStates = getAllPossibleStates(*currState);
        for (State<std::pair<int, int>>* nextState : possibleStates) {
            std::pair<int, int> nextPos = nextState->getState();
            int nextIndex = nextPos.first * maze_.getCols() + nextPos.second;
            if (!visited_[nextIndex]) {
                visited_[nextIndex] = true;
                queue.push_back(nextState);
            }
        }
    }
    cout << "Number of nodes evaluated: " << count << endl;
    // Clean up
    delete[] visited_;
    this->set_solution(solution);
}

void Maze2dSearchable::setVisited()
{
    this->visited_ = new bool[true];
}
void Maze2dSearchable::set_solution(Solution<std::pair<int, int>>* solution)
{
    this->solution_ = solution;
}

Solution<std::pair<int, int> >* Maze2dSearchable::getSolution()
{
    return this->solution_;
}
// ... (remaining code)
