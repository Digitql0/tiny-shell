#include "Terminal.h"
#include <iostream>

Terminal::Terminal()
{
    std::cout << "Made Terminal." << std::endl;
}

Terminal::~Terminal()
{
    std::cout << "Ended Terminal at: " << this << std::endl;
}