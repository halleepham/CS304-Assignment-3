//This file containes the class IMPLEMENTATION of the Infix_To_Postfix class which is used to convert an infix expression to a postfix expression

#include "Infix_To_Postfix.h"
#include <sstream>
#include <cctype>
using std::string;
using std::istringstream;

//variables that are used to later find if a character is an operator, parentheses, and find precendence of the operator
const string Infix_To_Postfix::OPERATORS = "+-*/%";
const int Infix_To_Postfix::PRECEDENCE[] = {1, 1, 2, 2, 2};
const string Infix_To_Postfix::OPEN = "([{";
const string Infix_To_Postfix::CLOSE = ")]}";

//PRE: takes in an infix expression
//POST: returns the infix expression in its postfix form
string Infix_To_Postfix::convert(const string& infix){
  postfix = "";
  //removes all items from the stack to ensure an clear stack
  while (!operator_stack.empty()){
    operator_stack.pop();
  }
  //uses tokens to retrieve each character in the expression
  istringstream infix_tokens(infix);
  string next_token;
  while(infix_tokens >> next_token){
    //if the token is an alphabetical or digital number, add to postifx
    if (isalnum(next_token[0])){
      postfix += next_token;
      postfix += " ";
    }
    //if the token is an operator or parentheses, process the operator
    else if (is_operator(next_token[0]) || is_open_parentheses(next_token[0]) || is_close_parentheses(next_token[0])){
      process_operator(next_token[0]);
    }
    else{
      //throw an error if the token is not a letter, number, operator, parentheses, or white space
      throw Syntax_Error("Unexpected Character Encountered");
    }
  }
  //remove item from the stack and add it to postfix
  while (!operator_stack.empty()){
    char op = operator_stack.top();
    operator_stack.pop();
    postfix += op;
    postfix += " ";
  }
  return postfix;
}

//PRE: takes in an operator
//POST: Determines and returns the precedence of the operator
int Infix_To_Postfix::precedence(char op) const{
  return PRECEDENCE[OPERATORS.find(op)];
}

//PRE: takes in a character
//POST: returns true if the character is an operator, otherwise false
bool Infix_To_Postfix::is_operator(char ch) const{
  return (OPERATORS.find(ch) != std::string::npos);
}

//PRE: takes in a character
//POST: returns true if the character is an open parentheses, otherwise false
bool Infix_To_Postfix::is_open_parentheses(char ch) const{
   return(OPEN.find(ch) != std::string::npos);
}

//PRE: takes in a character
//POST: returns true if the character is an closing parentheses, otherwise false
bool Infix_To_Postfix::is_close_parentheses(char ch) const{
   return (CLOSE.find(ch) != std::string::npos);
}

//PRE: takes in an operator (or parentheses)
//POST: no return, determines what order to add the operator/parentheses to the stack
void Infix_To_Postfix::process_operator(char op){
  //push operator/parenthese onto the stack
  if (operator_stack.empty() || is_open_parentheses(op)){
    operator_stack.push(op);
  }
    else{
      //add the operator/parentheses to the postfix taking into account precendence until the stack is empty
      while (!operator_stack.empty() && !is_open_parentheses(operator_stack.top()) && (precedence(op) <= precedence(operator_stack.top()))){
        postfix += operator_stack.top();
        postfix += " ";
        operator_stack.pop();
      }
      //if its a closing parentheses, remove and add operator to stack until there is a matching closing parentheses
      if(is_close_parentheses(op)){
        while (!operator_stack.empty() && !is_open_parentheses(operator_stack.top())){
          postfix += operator_stack.top();
          postfix += " ";
          operator_stack.pop();
        }
        if (!operator_stack.empty() && is_open_parentheses(operator_stack.top())){
          operator_stack.pop();
        }
        else{
          //throw error if there is unmatched parentheses
          throw Syntax_Error("Unmatched close parentheses");
        }
      }
      else{
        operator_stack.push(op);
      }
    }
  }



