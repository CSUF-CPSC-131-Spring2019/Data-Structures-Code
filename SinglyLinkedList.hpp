#pragma once

#include <stdexcept>

template<typename T>
struct Node {
    T data;
    Node<T>* next;

    Node() = delete;            // Intentionally no default constructor
    Node( const T & element ) : data( element ), next( nullptr ) {}
};


template<typename T>
class SinglyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
public:
    // Constructors
    SinglyLinkedList();
    SinglyLinkedList(const SinglyLinkedList&);
    SinglyLinkedList& operator=(const SinglyLinkedList&); // assignment operator
    ~SinglyLinkedList(); // destructor

    // Getters / Setters
    bool empty();
    int size() = delete; // INTENTIONALLY NOT IMPLEMENTED !!

    void append(  const T& );
    void prepend( const T& );
    void insertAfter( Node<T>*,  const T& );
    void removeAfter( Node<T>* );

    void pop_front();      // remove element at front of list
    T&   front();          // return list's front element
    T&   back();           // return list's back element

    void clear();
  };

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList() : head( nullptr ), tail( nullptr ) {}

template<typename T>
bool SinglyLinkedList<T>::empty() {
    return head == nullptr;
}

template<typename T>
void SinglyLinkedList<T>::append( const T& newData ) {
  Node<T> * newNode = new Node<T>( newData );   // create new node

  if (head == nullptr) { // List empty
     head = newNode;
     tail = newNode;
  }
  else{
     tail->next = newNode;
     tail = newNode;
  }
}

template<typename T>
void SinglyLinkedList<T>::prepend( const T& newData ) {
  Node<T> * newNode = new Node<T>( newData );   // create new node

  if (head == nullptr) { // list empty
     head = newNode;
     tail = newNode;
  }
  else {
     newNode->next = head;
     head = newNode;
  }
}


template<typename T>
void SinglyLinkedList<T>::insertAfter(Node<T>* curNode, const T& newData) {
    // Construct new node
    Node<T>* newNode = new Node<T>( newData );

    if (head == nullptr) {                // List empty
        head = newNode;
        tail = newNode;
    } else if (curNode == tail) {         // Insert after tail
        tail->next = newNode;
        tail = newNode;
    } else {
        newNode->next = curNode->next;
        curNode->next = newNode;
    }
}


template<typename T>
void SinglyLinkedList<T>::removeAfter(Node<T>* curNode) {
  if( empty() ) throw std::length_error( "empty list" );

  // Special case, remove head
  if (curNode == nullptr && head != nullptr) {
     Node<T> *sucNode = head->next;
     head = sucNode;

     if (sucNode == nullptr) { // Removed last item
        tail = nullptr;
     }
  }
  else if (curNode->next != nullptr) {
     Node<T> *sucNode = curNode->next->next;
     curNode->next = sucNode;

     if (sucNode == nullptr) { // Removed tail
        tail = curNode;
     }
  }
}


template <typename T>
void SinglyLinkedList<T>::pop_front() {
  removeAfter(nullptr);
}


template <typename T>
T& SinglyLinkedList<T>::front() {
  if( empty() ) throw std::length_error( "empty list" );
  return head->data;
}


template <typename T>
T& SinglyLinkedList<T>::back() {
  if( empty() ) throw std::length_error( "empty list" );
  return tail->data;
}


template<typename T>
void SinglyLinkedList<T>::clear() {
  while( !empty() )
    pop_front();
}


template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    clear();
}

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList( const SinglyLinkedList<T> & original ) : SinglyLinkedList() {
  // Walk the original list adding copies of the elements to this list maintaining order
  for( Node<T> * position = original.head; position != nullptr; position = position->next ) {
    append( position->data );
  }
}

template <typename T>
SinglyLinkedList<T> & SinglyLinkedList<T>::operator=( const SinglyLinkedList<T> & rhs ) {
  if( this != &rhs ) // avoid self assignment
  {
    // Release the contents of this list first
    clear();  // An optimization might be possible by reusing already allocated nodes

    // Walk the right hand side list adding copies of the elements to this list maintaining order
    for( Node<T> * position = rhs.head; position != nullptr; position = position->next ) {
      append( position->data );
    }
  }
  return *this;
}
