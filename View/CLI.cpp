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
        output_<< "Welcome to the best CLI ever!" << std::endl;
        output_<< "Please enter a command:" << std::endl;
        output_<< "This is a list of the commands:" << std::endl;
        output_<< "Press exit at any time to escape" << std::endl;
        for (auto it = commandMap_.begin(); it != commandMap_.end(); ++it)
        {
            output_ << it->first << std::endl;
        }
        output_ << "Enter command:" << std::endl;
        std::string userInput;
        std::getline(input_, userInput);

        if (userInput == "exit")
        {
            std::cout << "Bye Bye" << std::endl;
            std::cout <<"Hate to see you leave :(" << std::endl;
            return;
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
