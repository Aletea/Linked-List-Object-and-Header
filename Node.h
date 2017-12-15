#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "Student.h"

using namespace std;

class Node {
 public:
  Node();
  ~Node();
  void setStudent(Student* newS);
  Student* getStudent();
  void setNext(Node* newN);
  Node* getNext();
 private:
  Student* student;
  Node* next;
};
#endif
