//
// Doubly-linked list with 2 dummy nodes
//
#pragma once

#include <stdexcept>

template<typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node() = delete;            // Intentionally no default constructor
    Node( const T & element ) : data( element ), next( nullptr ), prev( nullptr ) {}
};


template<typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
public:
    // Constructors
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList&);
    DoublyLinkedList& operator=(const DoublyLinkedList&); // assignment operator
    ~DoublyLinkedList(); // destructor

    // Getters / Setters
    bool empty();
    int size() = delete; // INTENTIONALLY NOT IMPLEMENTED !!

    void append(  const T& );
    void prepend( const T& );
    void insertAfter( Node<T>*,  const T& );
    void remove( Node<T>* );

    void pop_front();      // remove element at front of list
    void pop_back();      // remove element at back of list
    T&   front();          // return list's front element
    T&   back();           // return list's back element

    void clear();
};

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
  head = new Node<T>( T() );      // create dummy nodes
  tail = new Node<T>( T() );
  head->next = tail;       // have them point to each other
  tail->prev = head;
}

template<typename T>
bool DoublyLinkedList<T>::empty() {
    return head->next == tail;
}

template<typename T>
void DoublyLinkedList<T>::append( const T& newData ) {
  Node<T> * newNode = new Node<T>( newData );   // create new node

  newNode->prev = tail->prev;
  newNode->next = tail;
  tail->prev->next = newNode;
  tail->prev = newNode;
}

template<typename T>
void DoublyLinkedList<T>::prepend( const T& newData ) {
  Node<T> * newNode = new Node<T>( newData );   // create new node

  Node<T> * firstNode = head->next;
  newNode->next = head->next;
  newNode->prev = head;
  head->next = newNode;
  firstNode->prev = newNode;
}


template<typename T>
void DoublyLinkedList<T>::insertAfter(Node<T>* curNode, const T& newData) {
    if (curNode == tail) {
       // Can't insert after dummy tail
       return;
    }
    // Construct new node
    Node<T>* newNode = new Node<T>( newData );

    Node<T>* sucNode = curNode->next;
    newNode->next = sucNode;
    newNode->prev = curNode;
    curNode->next = newNode;
    sucNode->prev = newNode;
}


template<typename T>
void DoublyLinkedList<T>::remove(Node<T>* curNode) {
  if( empty() ) throw std::length_error( "empty list" );

  if (curNode == head || curNode == tail) {
     // Dummy nodes cannot be removed
     return;
  }

  Node<T>* sucNode = curNode->next;
  Node<T>* predNode = curNode->prev;

  // Successor node is never null
  sucNode->prev = predNode;

  // Predecessor node is never null
  predNode->next = sucNode;
}


template <typename T>
void DoublyLinkedList<T>::pop_front() {
  remove(head->next);
}


template <typename T>
void DoublyLinkedList<T>::pop_back() {
  remove(tail->prev);
}


template <typename T>
T& DoublyLinkedList<T>::front() {
  if( empty() ) throw std::length_error( "empty list" );
  return head->next->data;
}


template <typename T>
T& DoublyLinkedList<T>::back() {
  if( empty() ) throw std::length_error( "empty list" );
  return tail->prev->data;
}


template<typename T>
void DoublyLinkedList<T>::clear() {
  while( !empty() )
    pop_front();
}


template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
    delete head;				            // remove the dummy nodes
    delete tail;
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList( const DoublyLinkedList<T> & original ) : DoublyLinkedList() {
  // Walk the original list adding copies of the elements to this list maintaining order
  for( Node<T> * position = original.head->next; position != original.tail; position = position->next ) {
    append( position->data );
  }
}

template <typename T>
DoublyLinkedList<T> & DoublyLinkedList<T>::operator=( const DoublyLinkedList<T> & rhs ) {
  if( this != &rhs ) // avoid self assignment
  {
    // Release the contents of this list first
    clear();  // An optimization might be possible by reusing already allocated nodes

    // Walk the right hand side list adding copies of the elements to this list maintaining order
    for( Node<T> * position = rhs.head->next; position != rhs.tail; position = position->next ) {
      append( position->data );
    }
  }
  return *this;
}
