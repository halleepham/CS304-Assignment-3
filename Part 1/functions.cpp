//This file contains the function defintions of functions used to determine balanced parentheses

#include "functions.h"


//string variables used containing open and close parentheses
const string OPEN = "([{";
const string CLOSE = ")]}";

//PRE: takes in a character
//POST: returns true if the character is a opening parentheses, false if it is not
bool is_open(char ch){
  return OPEN.find(ch) != string::npos;
}

//PRE: takes in a character
//POST: returns true if the character is a closing parentheses, false if it is not
bool is_close(char ch){
  return CLOSE.find(ch) != string::npos;
}

//PRE: takes in an infix expression
//POST: returns true if the expression has balanced parentheses, otherwise returns false
bool is_balanced(const string &expression){
  //creates an empty stack
  KW::stack<char> s;
  bool balanced = true;
  string::const_iterator iter = expression.begin();
  while (balanced && (iter != expression.end())){
    char next_ch = *iter;
    //checks if character is open parentheses and pushed onto the stack
    if (is_open(next_ch)){
      s.push(next_ch);
    }
    //if the character is a closing parentheses and the stack is empty, that means the expression is NOT balanced
    else if (is_close(next_ch)){
      if (s.empty()){
        balanced = false;
      }
      else{
        char top_ch = s.top();
        s.pop();
        //finds matching opening and closing parentheses
        balanced = (OPEN.find(top_ch) == CLOSE.find(next_ch));
      }
    }
    ++iter;
  }
  return balanced && s.empty();
}