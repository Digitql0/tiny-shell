#include <iostream>
#include "Terminal.h"
#include <string>

int main()
{
    std::cout << "Program started." << std::endl;
    Terminal terminal;

    while (true)
    {
        std::string command;
        std::cout << "$ ";
        std::getline(std::cin, command);
        // std::cout << std::endl;
        int syscall = terminal.handleCommand(command);
        std::cout << "-//  " << syscall << std::endl;

        if (syscall == 961)
        {
            std::cout << "Too many Arguments were given." << std::endl;
        }

        if (syscall == 962)
        {
            std::cout << "Not enough Arguments were given." << std::endl;
        }

        if (syscall == 1)
        {
            std::cout << "Ending Terminal..." << std::endl;
            break;
        }
    }

    return 0;
}
