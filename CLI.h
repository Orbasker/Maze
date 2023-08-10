#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include "command.cpp"

class CLI
{
public:
    CLI(std::istream &input, std::ostream &output);

    void addCommand(const std::string &commandName, Command *command);

    void start();

private:
    std::istream &input_;
    std::ostream &output_;
    std::unordered_map<std::string, Command *> commandMap_;
};