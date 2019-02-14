#include <iostream>
#include <stdexcept>
#include <string>

#include "DoublyLinkedList.hpp"

using std::cout;
using std::string;
using std::to_string;
using std::ostream;
using std::endl;


class Student
{
  private:
    string name_;
    int numOfSemesters_ = 0;

  public:
    Student() = default;
    Student( string name, int nsem = 1 ) : name_( name ), numOfSemesters_( nsem ) {}

    void updateNSemesters()          { numOfSemesters_++;      }
    void name( const string & name ) { name_           = name; }
    void semesters( int n )          { numOfSemesters_ = n;    }

  friend ostream& operator<<( ostream& os, const Student& student );
};

ostream& operator<<( ostream& os, const Student& student )
{
  os << "Name: " << student.name_;
  os << ". No. of semesters= " << student.numOfSemesters_ << endl;
  return os;
}


int main() {

    DoublyLinkedList<Student> students;

    Student s;
    for (int i = 0; i < 5; i++) {
        s.name("Student_" + to_string(i));
        s.semesters(2);
        students.prepend(s);
    }

    DoublyLinkedList<Student> classRoster( students ); // copy constructor
    for( int i = 1; i <= 5; i++ )
    {
        s.name( "Student_" + to_string( i*10 ) );
        s.semesters( 2 );
        classRoster.append( s );
    }

    students = classRoster; // assignment operator
    cout << classRoster.front() << classRoster.back();

    while (!students.empty()) {
        cout << students.front();
        students.pop_front();
    }
}

// template struct Node<Student>;
// template class DoublyLinkedList<Student>; // good idea to explicitly instantiate the templated class to force the compiler to check it
