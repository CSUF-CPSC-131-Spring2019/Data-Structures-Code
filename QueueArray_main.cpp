#include <iostream>
#include <stdexcept>

#include "QueueArray.hpp"

using std::cout;
using std::endl;

int main() {

    QueueArray<int> myQueue(10); // Array-based queue with capacity 10

    cout << "Pushing 10 ..." << endl;
    myQueue.push(10);
    cout << "Front of queue: " << myQueue.peek() << endl;

    cout << "Pushing 20 ..." << endl;
    myQueue.push(20);
    cout << "Front of queue: " << myQueue.peek() << endl;

    cout << "Pushing 30 ..." << endl;
    myQueue.push(30);
    cout << "Front of queue: " << myQueue.peek() << endl;

    cout << "Popping ..." << endl;
    myQueue.pop();
    cout << "Front of queue: " << myQueue.peek() << endl;

    cout << "Popping ..." << endl;
    myQueue.pop();
    cout << "Front of queue: " << myQueue.peek() << endl;

    cout << "Popping ..." << endl;
    myQueue.pop();

    if (myQueue.empty())
      cout << "queue is empty" << endl;
    else
      cout << "queue is not empty" << endl;
}
