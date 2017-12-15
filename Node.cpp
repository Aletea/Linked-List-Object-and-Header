#include <iostream>
#include "Node.h"
#include "Student.h"

using namespace std;

Node::Node() {
  student = NULL;
  next = NULL;
}

Node::~Node() {
  student = NULL;
  next = NULL;
}
void Node::setStudent(Student* newS) {
  student = newS;
}

Student* Node::getStudent() {
  return student;
}

void Node::setNext(Node* newN) {
  next = newN;
}

Node* Node::getNext() {
  return next;
}
