#include "Terminal.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

Terminal::Terminal()
{
    std::cout << "Made Terminal." << std::endl;
}

Terminal::~Terminal()
{
    std::cout << "Ended Terminal at: " << this << std::endl;
}

int Terminal::handleCommand(std::string command)
{
    std::vector<std::string> tokens = {};

    tokenize(tokens, command);

    if (tokens[0] == "exit")
    {
        return 1;
    }

    if (tokens[0] == "echo")
    {
        // std::cout << tokens.size() << std::endl;

        if (tokens.size() < 2)
        {
            return 962;
        }

        if (tokens.size() > 2)
        {
            return 961;
        }

        std::cout << tokens[1] << std::endl;
    }

    if (tokens[0] == "cls")
    {

        if (tokens.size() > 1)
        {
            return 961;
        }

        // std::system("cls"); //linux
        std::system("clear"); // windows
    }

    if (tokens[0] == "date")
    {

        if (tokens.size() > 1)
        {
            return 961;
        }

        std::time_t t = std::time(nullptr);
        std::cout << std::ctime(&t);
    }

    return 0;
}

void Terminal::tokenize(std::vector<std::string> &tokens, std::string command)
{
    std::string token;
    char separator = ' ';
    for (char c : command)
    {
        if (c == separator)
        {
            if (!token.empty()) // Avoid adding empty tokens
            {
                tokens.push_back(token);
                token = "";
            }
        }
        else
        {
            token += c;
        }
    }

    // Add the last token if it exists
    if (!token.empty())
    {
        tokens.push_back(token);
    }
}