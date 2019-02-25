// Implementation based on:
// Data Structures and Algorithms in C++, Goodrich, Tamassia, and Mount, 2nd Ed., 2011.
//
#pragma once

#include <stdexcept>

template<typename T>
class QueueArray {
private:
    T* Q;					    // array of queue elements
    size_t capacity;	// queue capacity
    size_t f;					// index of the front of the queue
    size_t r;					// index of the rear of the queue
    size_t n;					// number of elements
public:
    enum { DEF_CAPACITY = 100 };		// default queue capacity
    QueueArray(size_t cap = DEF_CAPACITY); // constructor
    ~QueueArray();          // destructor

    void push(  const T& x); // Inserts x at end of the queue
    void pop();             // Removes item at front of queue
    T& peek();              // Returns but does not remove item at the front of the queue
    bool empty();           // Returns true if queue has no items
};

template <typename T> // constructor from capacity
QueueArray<T>::QueueArray(size_t cap): capacity(cap), f(0), r(0), n(0) {
  Q = new T[capacity];
}

template <typename T>				// destructor
QueueArray<T>::~QueueArray() {
  delete [] Q;
}

template<typename T>
void QueueArray<T>::push( const T& newItem ) {
	if (n == capacity) throw std::length_error("push to full queue");
	Q[r] = newItem;
	r = (r + 1) % capacity;
	n++;
}

template <typename T>				// remove item at front of queue
void QueueArray<T>::pop() {
	if (empty()) throw std::length_error("pop from empty queue");
	f = (f + 1) % capacity;
	n--;
}

template<typename T>  // Returns but does not remove item at the front of the queue
T& QueueArray<T>::peek() {
	if (empty()) throw std::length_error("front of empty queue");
	return Q[f];
}

template<typename T>  // Returns true if queue has no items
bool QueueArray<T>::empty() {
  return (n == 0);
}
