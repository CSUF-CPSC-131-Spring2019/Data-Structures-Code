#pragma once

#include <stdexcept>

// Declaration
template <typename T>
class FixedVector {
private:
    size_t size_; // number of elements in the data structure
    const size_t capacity_; // length of the array
    T* array_; // pointer to dynamically allocated array

public:
    // Constructors
    FixedVector(size_t arraysize = 0);         // Also serves as default constructor
    FixedVector(const FixedVector& input );    // Copy constructor
    ~FixedVector();

    // Getters / Setters
    T& at(size_t index);
    T& operator[](size_t index);
    void push_back(const T& value);
    void set(size_t index, const T& value);
    void erase(size_t index);
    void insert(size_t beforeIndex, const T& value);
    size_t size();
    bool empty();
    void clear();

    // Overloaded Operators
    FixedVector& operator=(const FixedVector& rhs);  //Copy assignment
};

// Implementation

// Constructor with initial capacity argument
template <typename T>
FixedVector<T>::FixedVector(size_t arraysize) : size_(0), capacity_(arraysize) {
    array_ = new T[capacity_];
}

template <typename T>
size_t FixedVector<T>::size() {
    return size_;
}

template <typename T>
bool FixedVector<T>::empty() {
    return (size_ == 0);
}

template <typename T>
void FixedVector<T>::clear() {
    size_ = 0;
}

// Getter
template <typename T>
T& FixedVector<T>::at(size_t index) {
    if (index >= size_) {
        throw std::range_error( "index out of bounds" );
    }

    return array_[index];
}

// Getter
template <typename T>
void FixedVector<T>::push_back(const T& value) {
    insert( size_, value ); // delegate to insert() leveraging error checking
}

// Overloaded Array-Access Operator
template <typename T>
T& FixedVector<T>::operator[](size_t index) {
    return array_[index];  // Note: intentionally not checking array bounds
}

// Setter
template <typename T>
void FixedVector<T>::set(size_t index, const T& value) {
    at( index ) = value;  // delegate to at() leveraging error checking
}

// Removes element from position. Elements from higher positions are shifted back to fill gap.
// Vector size decrements
template <typename T>
void FixedVector<T>::erase(size_t index) {
    if (index >= size_) {
        throw std::range_error( "index out of bounds" );
    }

    // move elements to close the gap from the left and working right 
    for (size_t j = index + 1; j < size_; j++) { // shift elements to the left
        array_[j-1] = array_[j];
    }
    size_--;
}

// Copies x to element at position. Items at that position and higher are shifted over to make room. Vector size increments.
template <typename T>
void FixedVector<T>::insert(size_t beforeIndex, const T &value) {
    if( size_ >= capacity_) {
        throw std::range_error("insufficient capacity to add another element");
    }
    if( beforeIndex >  size_ ) {
        beforeIndex = size_;   // insert at the back
    } 

    // move elements to create space starting from the right and working left
    for( size_t j = size_; j > beforeIndex; j-- ) {
      array_[ j ] = array_[ j-1 ]; // shift elements to the right
    }

    array_[ beforeIndex ] = value; // put in empty slot
    size_++;
}

// Copy Constructor
template <typename T>
FixedVector<T>::FixedVector(const FixedVector<T>& input) : size_(input.size_), capacity_(input.capacity_) {
    array_ = new T[capacity_];

    // Copy each element from the input vector to this vector
    for (size_t i = 0; i < size_; i++) {
        array_[i] = input.array_[i];
    }
}

// Overloaded Assignment Operator
template <typename T>
FixedVector<T>& FixedVector<T>::operator=(const FixedVector<T>& rhs) {
    if (this != &rhs) {
        // Being fixed size, the already allocated array can be reused
        // Capacity is not adjusted.  If capacity_ < rhs.capacity, then some
        // rhs elements may not be copied.
        for (size_ = 0; size_ < rhs.size_  &&  size_ < capacity_ ; ++size_ ) {
            array_[size_] = rhs.array_[size_];
        }
    }
    return *this;
}

// Destructor
template <typename T>
FixedVector<T>::~FixedVector() {
    delete[] array_;
}
