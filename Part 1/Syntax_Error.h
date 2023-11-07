//This file contains the implementation of the syntax error

#ifndef SYNTAX_ERROR_H
#define SYNTAX_ERROR_H
#include <stdexcept>

//This class throws a syntax error when called
class Syntax_Error : public std::invalid_argument{
  public:
    Syntax_Error(std::string msg) : std::invalid_argument(msg) {}
};
#endif