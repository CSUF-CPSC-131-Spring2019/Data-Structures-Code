#pragma once

// comment line

#include <stdexcept>
#include <algorithm> // needed for std::max in ExtendableVector::insert()
using namespace std;

const size_t DEFAULT_CAPACITY = 100;

#pragma once

#include <stdexcept>
using namespace std;


// Declaration
template <typename T>
class ExtendableVector {
private:
    size_t size_;
    size_t capacity_;
    T* array_;

public:
    // Constructors
    ExtendableVector(size_t arraysize = DEFAULT_CAPACITY);
    ExtendableVector(const ExtendableVector&);
    ExtendableVector& operator=(const ExtendableVector&); // Assignment operator
    ~ExtendableVector(); // destructor

    // Getters / Setters
    T& at(size_t);
    T& operator[](size_t);
    void push_back(const T&);
    void set(size_t, const T&);
    void erase(size_t);
    void insert(size_t, const T&);
    size_t size();
    bool empty();
    void clear();

private:
    void reserve(size_t); // helper function to change capacity

};


// Constructor with initial capacity argument
template <typename T>
ExtendableVector<T>::ExtendableVector(size_t arraysize) {
    if (arraysize < 0) {
        throw invalid_argument("size is less than 0");
    }
    size_ = 0;
    capacity_ = arraysize;
    array_ = new T[capacity_];
}

template <typename T>
size_t ExtendableVector<T>::size() {
    return size_;
}

template <typename T>
bool ExtendableVector<T>::empty() {
    return (size_ == 0);
}

template <typename T>
void ExtendableVector<T>::clear() {
    size_ = 0;
}

// Getter
template <typename T>
T& ExtendableVector<T>::at(size_t index) {
    if ((index < 0) || (index >= size_)) {
        throw range_error("index out of bounds");
    }
    return array_[index];
}

// Getter
template <typename T>
void ExtendableVector<T>::push_back(const T &value) {
    if (size_ >= capacity_) // If at max capacity, double the capacity
        reserve (2 * capacity_);
    array_[size_] = value;
    size_++;
}

// Overloaded Array-Access Operator
template <typename T>
T& ExtendableVector<T>::operator[](size_t index) {
    return array_[index];
}

// Setter
template <typename T>
void ExtendableVector<T>::set(size_t index, const T &value) {
    array_[index] = value;
}

// Removes element from position. Elements from higher positions are shifted back to fill gap.
// Vector size decrements
template <typename T>
void ExtendableVector<T>::erase(size_t index) {
    for (int j = index+1; j < size_; j++) // shift elements to the left
        array_[j-1] = array_[j];
    size_--;
}

// Copies x to element at position. Items at that position and higher are shifted over to make room. Vector size increments.
template <typename T>
void ExtendableVector<T>::insert(size_t index, const T &value) {
    if (size_ >= capacity_) // If at max capacity, double the capacity
        reserve (2 * capacity_);
    for (size_t j = size_ - 1; j >= index; j--) // move elements to create space for value
        array_[j+1] = array_[j]; // shift elements to the right
    array_[index] = value; // put in empty slot
    size_++;
}

template <typename T>
void ExtendableVector<T>::reserve(size_t newCapacity) {
    if (newCapacity > capacity_) {
        T* newArray = new T[newCapacity];
        // Copy values to new array
        for (size_t i = 0; i < size_; i++) {
            newArray[i] = array_[i];
        }
        delete[] array_;
        array_ = newArray;
        capacity_ = newCapacity;
    }
}

// Copy Constructor
template <typename T>
ExtendableVector<T>::ExtendableVector(const ExtendableVector<T>& input) {
    size_ = input.size_;
    capacity_ = input.capacity_;
    array_ = new T[capacity_];
    for (size_t i = 0; i < size_; i++) {
        array_[i] = input.array_[i];
    }
}

// Overloaded Assignment Operator
template <typename T>
ExtendableVector<T>& ExtendableVector<T>::operator=(const ExtendableVector<T>& rhs) {
    if (this != &rhs) {
        delete[] array_;
        size_ = rhs.size_;
        capacity_ = rhs.capacity_;
        array_ = new T[size_];
        for (size_t i = 0; i < size_; i++) {
            array_[i] = rhs.array_[i];
        }
    }
    return *this;
}

// Deconstructor
template <typename T>
ExtendableVector<T>::~ExtendableVector() {
    delete[] array_;
}
