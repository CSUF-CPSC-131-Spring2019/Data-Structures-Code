#include <iostream>
#include <stdexcept>

#include "StackLinkedList.hpp"

using std::cout;
using std::endl;

int main() {

    StackLinkedList<int> myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    cout << "Top of stack: " << myStack.peek() << endl;
    myStack.pop();
    myStack.pop();
    cout << "Top of stack: " << myStack.peek() << endl;
    myStack.pop();
    if (myStack.empty())
      cout << "Stack is empty" << endl;
    else
      cout << "Stack is not empty" << endl;
}
