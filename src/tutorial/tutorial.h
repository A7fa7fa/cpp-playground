#pragma once
#include <iostream>
#include <string.h>

namespace tutorial {
    #define log(message) std::cout << message << std::endl;
    void charArray();
    void stdString();
    // void log(const char* message);
    // void log(std::string message);
    void pointer();
}