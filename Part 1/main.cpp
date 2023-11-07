//This file is the main source file where the infix expression is inputted by the user

#include <iostream>
#include <vector>

#include "functions.h"
#include "Syntax_Error.h"
#include "stack.h"
#include "Infix_To_Postfix.h"
using namespace std;

/*ASSUMPTIONS:
-The user MUST enter the infix expression with spaces inbetween each character
-The expression only contains numbers, operators, parentheses, and spaces
*/

int main() {
  string infix = "", postfix = "";
  Infix_To_Postfix infix_to_postfix;
  cout << "PLEASE input infix expression with spaces inbetween EACH character" << endl;
  cout << "Example:\n 3 + { ( 4 * 7 ) / 2 }\n NOT: 3+{(4 * 7)/2}" << endl << endl;
  //ask user for an infix expression
  cout << "Enter an infix expression: ";
  //user inputs the infix expression
  while (getline(cin, infix) && (infix != "")){
    if(infix == "q"){
      break;
    }
    cout << infix;
    //checks if the the expression is balanced, if it is, convert to postfix
    if (is_balanced(infix)){
      cout << " is balanced\n";
      cout << "Converting to postfix...\n\n";
      postfix = infix_to_postfix.convert(infix);
      cout << postfix << endl << endl;
    }
    //if not balanced ask for another infix expression
    else{
      cout << " is not balanced\n\n";
    }
    cout << "Enter another infix expression or enter 'q' to quit: " ;
  }
}