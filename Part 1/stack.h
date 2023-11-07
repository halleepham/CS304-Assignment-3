#ifndef STACK_H_
#define STACK_H_
#include <vector>
//This file includes BOTH the definition and implementation of a stack class using namespace KW (different from the standard library stack class)

namespace KW{
  template<typename Item_Type>
    class stack{
      public:
        stack();
        void push(const Item_Type& item);
        Item_Type& top();
        void pop();
        bool empty() const;
        std::size_t size() const;
      private:
        //This stack implementation uses the vector class as the underlying container
        std::vector<Item_Type> container;
    };
  #ifndef STACK_TC_
  #define STACK_TC_

  //PRE: No preconditions
  //POST: Creates an empty stack item
  template<typename Item_Type>
    stack<Item_Type>::stack(){ }

  //PRE: takes in an item and stack
  //POST: pushes the item onto the top of the stack
  template<typename Item_Type>
    void stack<Item_Type>::push(const Item_Type& item){
      container.push_back(item);
    }

  //PRE: takes in a stack
  //POST: returns the item on the top of the stack (using the delegation from the standard library class vector)
  template<typename Item_Type>
    Item_Type& stack<Item_Type>::top(){
      return container.back();
    }

  //PRE: takes in a stack
  //POST: removes the item from the top of the stack (using the delegation from the standard library class vector)
  template<typename Item_Type>
    void stack<Item_Type>::pop(){
      container.pop_back();
    }

  //PRE: takes in a stack
  //POST: determines if the stack is empty (using the delegation from the standard library class vector)
  template<typename Item_Type>
    bool stack<Item_Type>::empty() const{
      return container.empty();
    }

  //PRE: takes in a stack
  //POST: returns the number of items in the stack (using the delegation from the standard library class vector)
  template<typename Item_Type>
    std::size_t stack<Item_Type>::size() const{
      return container.size();
    }
  #endif
  
}

#endif