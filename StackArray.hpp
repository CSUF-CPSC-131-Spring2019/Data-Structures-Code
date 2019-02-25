// Implementation based on:
// Data Structures and Algorithms in C++, Goodrich, Tamassia, and Mount, 2nd Ed., 2011.
//
#pragma once

#include <stdexcept>

template<typename T>
class StackArray {
private:
    T* S;					// array of stack elements
	  int capacity;	// stack capacity
	  int t;				// index of the top of the stack
public:
    enum { DEF_CAPACITY = 100 };		// default stack capacity
    StackArray(size_t cap = DEF_CAPACITY); // constructor
    ~StackArray();          // destructor

    void push(  const T& x); // Inserts x on top of stack
    void pop();             // Removes item at top of stack
    T& peek();              // Returns but does not remove item at top of stack
    bool empty();           // Returns true if stack has no items
};

template <typename T>				// constructor from capacity
StackArray<T>::StackArray(size_t cap) : capacity(cap), t(-1) {
  S = new T[capacity];
}

template <typename T>				// destructor
StackArray<T>::~StackArray() {
  delete [] S;
}

template <typename T>				// push element onto the stack
void StackArray<T>::push( const T& newItem) {
	if (t+1 == capacity) throw std::length_error("Push to full stack");
	S[++t] = newItem;
}

template <typename T>				// pop the stack
void StackArray<T>::pop() {
	if (empty()) throw std::length_error("Pop from empty stack");
	--t;
}

template<typename T>
T& StackArray<T>::peek() { // return top of stack
  if (empty()) throw std::length_error("Top of empty stack");
	return S[t];
}

template<typename T>
bool StackArray<T>::empty() { 	// is the stack empty?
  return (t < 0);
}
