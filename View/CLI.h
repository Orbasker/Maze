#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include "Controller/command.cpp"

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
// #include "../Controller/Command.h"

class CLI
{
public:
    CLI(std::istream &input, std::ostream &output);

    void addCommand(const std::string &commandName, Command *command);
    void printMenu();
    void start();

private:
    std::istream &input_;
    std::ostream &output_;
    std::unordered_map<std::string, Command *> commandMap_;
};
