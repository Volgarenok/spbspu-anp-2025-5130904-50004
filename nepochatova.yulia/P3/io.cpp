#include "io.hpp"
#include <iostream>
#include <stdexcept>
#include <fstream>

int Nepochatova::checkArgs(int argc, char ** argv){
    if (argc < 4){ throw std::invalid_argument("Not enough arguments");}
    if (argc > 4){ throw std::invalid_argument("Too many argumenst");}

    const char * p = argv[1];
    if (*p > 2){ throw std::invalid_argument("First parametr is out of range");}

    if (*p == /0){ throw std::invalid_argument("First parametr is not a number");}
    while (*p){
        if (*p < '0' || *p > '9') { throw std::invalid_argument("First parametr is not a number"); ++p;}
    }
}




