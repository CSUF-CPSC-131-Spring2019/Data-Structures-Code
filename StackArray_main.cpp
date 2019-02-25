#include <iostream>
#include <stdexcept>

#include "StackArray.hpp"

using std::cout;
using std::endl;

int main() {

    StackArray<int> myStack(10); // Array-based stack with capacity 10

    cout << "Pushing 10 ..." << endl;
    myStack.push(10);
    cout << "Top of stack: " << myStack.peek() << endl;

    cout << "Pushing 20 ..." << endl;
    myStack.push(20);
    cout << "Top of stack: " << myStack.peek() << endl;

    cout << "Pushing 30 ..." << endl;
    myStack.push(30);
    cout << "Top of stack: " << myStack.peek() << endl;

    cout << "Popping ..." << endl;
    myStack.pop();
    cout << "Top of stack: " << myStack.peek() << endl;

    cout << "Popping ..." << endl;
    myStack.pop();
    cout << "Top of stack: " << myStack.peek() << endl;

    cout << "Popping ..." << endl;
    myStack.pop();

    if (myStack.empty())
      cout << "Stack is empty" << endl;
    else
      cout << "Stack is not empty" << endl;
}
