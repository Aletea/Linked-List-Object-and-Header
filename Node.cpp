#include <iostream>
#include "Node.h"
#include "Student.h"

using namespace std;

//creates empty node
Node::Node() {
  student = NULL;
  next = NULL;
}

//empties node variables
Node::~Node() {
  student = NULL;
  next = NULL;
}
//setters and getters
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
