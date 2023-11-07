//This file contains both the DECLARATION and IMPLEMENTION of a queue class using a list as an underlying container (they are in the same file in order to properly define namespace KW)
#ifndef QUEUE_H
#define QUEUE_H

#include <list>

namespace KW{
  template<typename Item_Type>
    class Queue{
      public:
        Queue();
        void push(const Item_Type& item);
        Item_Type pop();
        Item_Type& front();
        bool empty() const;
        std::size_t size() const;
        void printQueue();
      private:
        //uses the standard library list class as the underlying container
        std::list<Item_Type> container;
    };

  //Member function IMPLEMENTATION
  #ifndef QUEUE_TC_
  #define QUEUE_TC_

  //PRE: no parameters
  //POST: constructs and empty queue
  template<typename Item_Type>
    Queue<Item_Type>::Queue(){}

  //PRE: takes in an item and a queue container
  //POST: pushes the item to the back of the queue
  template<typename Item_Type>
    void Queue<Item_Type>::push(const Item_Type& item){
      container.push_back(item);
    }
  
  //PRE: takes in the queue container
  //POST: removes the front element of the queue and returns it
  //Throws an error and stops program if queue is empty
  template<typename Item_Type>
    Item_Type Queue<Item_Type>::pop(){
      Item_Type front = this->front();
      container.pop_front();
      return front;
    }

  //PRE: takes in the queue container
  //POST: returns the front element present in the queue without removing it
  //Throws an error and stops program if queue is empty
  template<typename Item_Type>
    Item_Type& Queue<Item_Type>::front(){
      return container.front();
    }

  //PRE: takes in the queue container
  //POST: returns true if the queue is empty, returns false otherwise
  template<typename Item_Type>
    bool Queue<Item_Type>::empty() const{
      return container.empty();
    }

  //PRE: takes in the queue container
  //POST: returns the total number of elements present in the queue
  template<typename Item_Type>
    std::size_t Queue<Item_Type>::size() const{
      return container.size();
    }

  //PRE: takes in the queue conatiner
  //POST: no return, prints out the items in the queue without removing them
  template<typename Item_Type>
    void Queue<Item_Type>::printQueue(){
      std::cout << "The current queue:\n\n";
      std::cout << "\tFRONT\n\n";
      //uses list begin and end iterators to loop through the queue
      for (auto it = this->container.begin(); it != this->container.end(); ++it){
        std::cout << "\t" << *it << "\n";
      }
      std::cout << "\n\tBACK\n\n";
    }
  #endif
}

#endif