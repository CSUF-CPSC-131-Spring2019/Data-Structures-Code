#include <iostream>
#include <string>

#include "FixedVector.hpp"
using std::cout;
using std::string;
using std::ostream;
using std::endl;

class Student {
private:
    string name_;
    int numOfSemesters_;

public:
    Student() = default;

    Student (string name, int nsem=1): name_(name), numOfSemesters_(nsem) {}

    void updateNSemesters() {
        numOfSemesters_++;
    }

    friend ostream& operator<<(ostream& os, const Student& student);
};

ostream& operator<<(ostream& os, const Student& student) {
  os << "Name: " << student.name_;
  os << ". No. of semesters= " << student.numOfSemesters_ << endl;
  return os;
}

int main() {
    FixedVector<Student> studentVector(10);

    Student s("Adam", 2);
    studentVector.push_back(s);
    studentVector.push_back(Student("Bob", 1));
    studentVector.push_back(Student("Dolores", 3));
    for (size_t i = 0; i < studentVector.size(); i++) {
      cout << studentVector[i];
    }

    // add student Carla between Bob and Dolores
    studentVector.insert(2, Student("Carla"));
    for (size_t i = 0; i < studentVector.size(); i++) {
      cout << studentVector[i];
    }

    // update Carla's record
    studentVector[2].updateNSemesters();
    cout << studentVector[2];

    // remove student Adam (element at index 0)
    studentVector.erase(0);
    for (size_t i = 0; i < studentVector.size(); i++) {
      cout << studentVector[i];
    }

}
