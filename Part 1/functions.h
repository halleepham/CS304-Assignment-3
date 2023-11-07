//This file contains function declarations that are used to determine if an expression has balanced parentheses

#include <iostream>
#include <string>
#include "Syntax_Error.h"
#include "stack.h"
using namespace std;

bool is_open(char ch);
bool is_close(char ch);
bool is_balanced(const string &expression);