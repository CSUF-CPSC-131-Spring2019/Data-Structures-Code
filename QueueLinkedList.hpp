#pragma once

#include "SinglyLinkedList.hpp"
#include <stdexcept>

template<typename T>
class QueueLinkedList {
private:
    SinglyLinkedList<T> list;
public:
    QueueLinkedList() = default;

    void push(  const T& x); // Inserts x at end of the queue
    void pop();             // Removes item at front of queue
    T& peek();              // Returns but does not remove item at the front of the queue
    bool empty();           // Returns true if queue has no items
};

template<typename T>
void QueueLinkedList<T>::push( const T& newItem ) {
   list.append(newItem); // Insert as list tail (end of queue)
}

template<typename T>
void QueueLinkedList<T>::pop() {
   list.removeAfter(nullptr);  // Remove list head
}

template<typename T>
T& QueueLinkedList<T>::peek() {
   return list.front();
}

template<typename T>
bool QueueLinkedList<T>::empty() {
   return list.empty();
}
