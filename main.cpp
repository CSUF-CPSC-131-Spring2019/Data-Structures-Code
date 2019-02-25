#include <iostream>

#include "SinglyLinkedList.hpp"

using std::cout;
using std::endl;


int main() {

    SinglyLinkedList<int> ds;
    for (int i=10; i<20; i++)
      ds.append(i);

    Node<int> *ptr = ds.find(15);
    if (ptr != nullptr)
      cout << "Found: " << ptr->data << " matches " << 15 << endl;
    else
      cout << "15 not found" << endl;

    ptr = ds.find(30);
    if (ptr != nullptr)
      cout << "Found: " << ptr->data << " matches " << 30 << endl;
    else
      cout << "30 not found" << endl;

    return 0;
}
