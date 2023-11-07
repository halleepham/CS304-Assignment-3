//This file containes the class DECLARATION of the Infix_To_Postfix class which is used to convert an infix expression to a postfix expression
#ifndef INFIX_TO_POSTFIX_H_
#define INFIX_TO_POSTFIX_H_

#include "Syntax_Error.h"
#include <string>
//#ifdef USEKW
#include "stack.h"
//#endif


class Infix_To_Postfix{
  public:
    std::string convert(const std::string& infix);
  private:
    void process_operator(char op);
    int precedence(char op) const;
    bool is_operator(char ch) const;
    bool is_open_parentheses(char ch) const;
    bool is_close_parentheses(char ch) const;


    static const std::string OPERATORS;
    static const int PRECEDENCE[];
    static const std::string OPEN;
    static const std::string CLOSE;
    //#ifdef USEKW
    KW::stack<char> operator_stack;
    //#endif
    std::string postfix;
};

#endif