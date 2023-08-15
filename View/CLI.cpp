// Or Basker   316388743
// Nave Maymon 318887965

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
        // output_<< "Welcome to the best CLI ever!" << std::endl;
        // print commands
        printMenu();

        output_<< "Please enter a command:" << std::endl;
       
        std::string userInput;
        std::getline(input_, userInput);

        if (userInput == "exit")
        {
            std::cout <<BLUE<< "Bye Bye" << std::endl;
            std::cout <<"Hate to see you leave :(" <<RESET<< std::endl;
            return;
        }

        auto it = commandMap_.find(userInput);
        if (it != commandMap_.end())
        {
            it->second->execute();
        }
        else
        {
            output_ <<RED<< "Unknown command: " << userInput << std::endl;
        }
    }
}


void CLI::printMenu()
{
    output_<< BOLD<<MAGENTA <<"Welcome to the best CLI ever!" << std::endl;
    output_<<CYAN << "This is a list of the commands:" << std::endl;
    output_<< CYAN<<"Press exit at any time to escape" << RESET<<std::endl;
    //lets print it nice with tabs instead of enter

    for (auto it = commandMap_.begin(); it != commandMap_.end(); ++it)
    {
        output_ << BOLD<<it->first << RESET << "        ";
    }
    output_<<BOLD<<"end"<<RESET<<std::endl;
}