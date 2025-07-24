#ifndef TERMINAL_H
#define TERMINAL_H

#include <iostream>
#include <vector>

class Terminal
{
public:
    Terminal();
    ~Terminal();
    int handleCommand(std::string command);

private:
    void tokenize(std::vector<std::string> &tokens, std::string command);
};

#endif
