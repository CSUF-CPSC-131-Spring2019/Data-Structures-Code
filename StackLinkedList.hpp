#pragma once

#include "SinglyLinkedList.hpp"
#include <stdexcept>

template<typename T>
class StackLinkedList {
private:
    SinglyLinkedList<T> list;
public:
    StackLinkedList() = default;

    void push(  const T& x); // Inserts x on top of stack
    void pop();             // Removes item at top of stack
    T& peek();              // Returns but does not remove item at top of stack
    bool empty();           // Returns true if stack has no items
};

template<typename T>
void StackLinkedList<T>::push( const T& newItem ) {
   list.prepend(newItem); // Insert as list head (top of stack)
}

template<typename T>
void StackLinkedList<T>::pop() {
   list.removeAfter(nullptr);   // Remove list head
}

template<typename T>
T& StackLinkedList<T>::peek() {
   return list.front();
}

template<typename T>
bool StackLinkedList<T>::empty() {
   return list.empty();
}
