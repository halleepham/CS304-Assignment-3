//This file contains the main source code

#include <iostream>
#include <string>
#include "Queue.h"
using namespace KW;

int main() {
  int choice;
  std::string userInput = "";
  //creates an empty queue
  Queue<std::string> queue;

  //The following code block displays the options
  //FOR GRADER: input one of the following integers from the option menu to execute a function to the queue
  std::cout << "Options:\n";
  std::cout << "\t1 - Insert a new element at the rear of the queue (.push())\n";
  std::cout << "\t2 - Remove the front element of the queue and return it (.pop())\n";
  std::cout << "\t3 - Return the front element present in the queue without removing it(.front())\n";
  std:: cout << "\t4 - Check if the queue is empty (.empty())\n";
  std::cout << "\t5 - Return the total number of elements present in the queue (.size())\n";
  std::cout << "\t0 - Quit\n\n";
  std::cout << "---------------------------\n";

  
  while (true){
    //asks the user for their input
    std::cout << "Enter which option you would like to do --> ";
    std::cin >> choice;
    std::cout << "\n";

    //executes the choice that the user inputted and prints current queue after every action
    if(choice == 0){
      std::cout << "Thanks for using this program!";
      break;
    }
    //FOR THE GRADER: push() function
    else if(choice == 1){
      std::cout << "What name would you like to add to the queue? --> ";
      std::cin >> userInput;
      std::cout << "Adding to the end of the queue...\n\n";
      queue.push(userInput);
      queue.printQueue();
    }
      
    //FOR THE GRADER: pop() function
    else if(choice == 2){
      std::cout << "Removing front element and returning it...\n";
      std::cout << "Removed " << queue.pop() << "\n\n";
      queue.printQueue();
    }
      
    //FOR THE GRADER: front() function
    else if(choice == 3){
      std::cout << "Returning the first front item without removing it...\n";
      std::cout << "Front element: " << queue.front() << "\n\n";
      queue.printQueue();
    }
      
    //FOR THE GRADER: empty() function
    else if(choice == 4){
      std::cout << "Checking if the queue is empty...\n";
      if(queue.empty()){
        std::cout << "The queue is empty\n\n";
      }
      else{
        std::cout << "The queue NOT empty\n\n";
      }
      queue.printQueue();
    }
      
    //FOR THE GRADER: size() function
    else if(choice == 5){
      std::cout << "Returning the total number of elements in the queue...\n";
      std::cout << "Total number of items: " << queue.size() << "\n\n";
      queue.printQueue();
    }
    else{
      std::cout << "Please enter a valid option.\n";
      continue;
    }
    std::cout << "---------------------------\n";
  }
}
