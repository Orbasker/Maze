#include "SolveMazeCommand.h"

void SolveMazeCommand::execute()
{
    std::unordered_map<std::string, Maze2d> mazes_;
    Maze2d maze_;

    mazes_ = model_->getMazes();
    for (auto it = mazes_.begin(); it != mazes_.end(); ++it)
    {
        std::cout << it->first << std::endl;
    }
    if (!mazes_.empty())
    {
        std::cout << "Please choose a maze from the list below or create a new one" << std::endl;
        for (const auto &entry : mazes_)
        {
            std::cout << entry.first << std::endl;
        }

        std::string name;
        std::cin >> name;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline character


        auto it = mazes_.find(name);
        if (it != mazes_.end())
        {
            maze_ = it->second;
            std::cout << "Chosen maze is: " << name << std::endl;
            maze_.print();

            std::cout << "Please choose an algorithm from the list below" << std::endl;
            std::string algo;
            std::cin >> algo;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline character


            std::cout << "Chosen algorithm is: " << algo << std::endl;

            try
            {
                model_->solveMaze(name, algo);
            }
            catch (const std::exception &e)
            {
                std::cout << e.what() << std::endl;
            }
        }
        else
        {
            std::cout << "Maze not found" << std::endl;
        }
    }
    else
    {
        std::cout << "No mazes in the cache yet, let's create one" << std::endl;

        std::cout << "Write name to create a new maze: ";
        std::string new_name;
        std::cin >> new_name;

        std::cout << "Please enter maze size: ";
        int maze_size;
        std::cin >> maze_size;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline character

        SimpleMaze2dGenerator generator;
        generator.generate(maze_size, maze_size);
        Maze2d maze = generator.getMaze();

        std::cout << "New maze name is: " << new_name << std::endl;
        std::cout << "New maze size is: " << maze_size << std::endl;
        std::cout << "New maze is: " << std::endl;
        maze.print();

        mazes_[new_name] = maze;
        model_->addMaze(new_name, maze);
        maze_ = maze;

        std::cout << "Please choose an algorithm from the list below: ";
        std::string algo;
        std::cin >> algo;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline character
        std::cout << "algo is: " << algo << endl;
        std::cout << "sending to modal solve maze" << endl;
        try
        {
            model_->solveMaze(new_name, algo);
            std::cout << "solved maze!" << endl;
            std::cout << "Solution for maze " << new_name << " is:" << std::endl;
            std::cout << "getting solution from model" << endl;
            Solution<std::pair<int, int>> *solut;
            solut = model_->getSolution(new_name);
            std::cout << "got solution from modal" << endl;
            view_->displaySolution(*solut);
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}
