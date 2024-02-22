#include <iostream>
#include <string>
#include "tutorial.h"

void tutorial::charArray() {

    const char* name = "my name"; // char string array. pointer points to start of string
    std::cout << name << std::endl;
    char* name_mutabl = (char*)"mutable"; // stack allocated
    log(name_mutabl);
    // name_mutabl[1] = 'M'; // undefined behaviour. not allowed to change
    log(name_mutabl);

    char name_mutabl2[] = "changed";
    log(name_mutabl2);
    name_mutabl2[0] = 'C';
    name_mutabl2[1] = 'C';
    log(name_mutabl2);

    char name2[5] = {'N', 'a', 'm', 'e', 0}; // init as char arra with null temrination character. length is unknow. but ends at termination character
    log(name2);
};

void tutorial::stdString() {

    std::string name = "manuel";
    log(name + ": size:" + std::to_string(name.size()));

    name += "lastname";
    log(name);

    std::string var = std::string("manuel") + "Hello!";
    std::cin.get();
};

// void tutorial::log(const char* message) {
//     std::cout << message << std::endl;
// }

// void tutorial::log(std::string message) {
//     std::cout << message << std::endl;
// }
