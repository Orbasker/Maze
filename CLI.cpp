#include "CLI.h"

CLI::CLI(std::istream &input, std::ostream &output) : input_(input), output_(output) {}

void CLI::addCommand(const std::string &commandName, Command *command)
{
    commandMap_[commandName] = command;
}

void CLI::start()
{
    while (true)
    {
        std::string userInput;
        std::getline(input_, userInput);

        if (userInput == "exit")
        {
            std::cout << "Bye Bye" << std::endl;
            std::cout <<"Hate to see you leave :(" << std::endl;
            break;
        }

        auto it = commandMap_.find(userInput);
        if (it != commandMap_.end())
        {
            it->second->execute();
        }
        else
        {
            output_ << "Unknown command: " << userInput << std::endl;
        }
    }
}
