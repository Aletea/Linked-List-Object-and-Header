#include <iostream>
#include <cstring>
#include "Node.h"
#include "Student.h"

using namespace std;

Student* addStudent();
void addNode(Student* student, Node* &current, Node* &start);
void printNode(Node* start);
void deleteStudent(char studentName[], Node* &start, Node* current);

int main() {
  Node* start = NULL;
  Node* current = start;
  bool adding = true;
  while (adding == true) {
    char* input = new char[80];
    do {
      cout << "'add' 'quit' 'delete' or 'print'?" << endl;
      input = new char[80];
      cin.get(input, 80);
      cin.get();
    } while (strcmp(input, "add") != 0 && strcmp(input, "print") != 0 && strcmp(input, "quit") != 0 && strcmp(input, "delete") != 0);
    if (strcmp(input, "add") == 0) {
      Student* newStudent = addStudent();
      addNode(newStudent, current, start);
    }
    else if (strcmp(input, "quit") == 0) {
      break;
    }
    else if(strcmp(input, "delete") == 0) {
      cout << "Student Name: ";
      char studentName[80];
      cin.get(studentName, 80);
      cin.get();
      deleteStudent(studentName, start, start);
    }
    else {
      printNode(start);
    }
  }
  return 0;
}

Student* addStudent() {
  cout << "First Name: ";
  char* firstName = new char[40];
  cin.get(firstName, 40);
  cin.get();
  cout << "Last Name: ";
  char* lastName = new char[40];
  cin.get(lastName, 40);
  cin.get();
  cout << "ID: ";
  int ID;
  cin >> ID;
  cin.ignore();
  cout << "GPA: ";
  double GPA;
  cin >> GPA;
  cin.ignore();
  Student* newStudent = new Student(firstName, lastName, ID, GPA);
  return newStudent;
}

void addNode(Student* student, Node* &current, Node* &start) {
  Node* newNode = new Node();
  newNode->setStudent(student);
  if (start == NULL) {
    start = newNode;
    current = start;
    return;
  }
  if (current != NULL && current->getNext() == NULL) {
    current->setNext(newNode);
    current = newNode;
  
    return;
  }
  if (current != NULL && current->getNext() != NULL) {
    current = current->getNext();
    addNode(student, current, start);
  }
}

void printNode(Node* start) {
  Node* current = start;
  Student* currentStudent = current->getStudent();
  cout << "Name: " << currentStudent->getName() << endl;
  cout << "ID: " << currentStudent->getID() << endl;
  cout << "GPA: " << currentStudent->getGPA() << endl;
  cout << endl;
  if (current->getNext() != NULL) {
    current = current->getNext();
    printNode(current);
  }
  return;
}

void deleteStudent(char studentName[], Node* &start, Node* current) {
  if (current == start && strcmp(current->getStudent()->getName(), studentName) == 0) {
    start = current->getNext();
    delete current;
    return;
  }
  else if (current->getNext() == NULL) {
    cout << "Could not find student" << endl;
    return;
  }
  else if (strcmp(current->getNext()->getStudent()->getName(), studentName) == 0) {
    Node* deleteNode = current->getNext();
    current->setNext(current->getNext()->getNext());
    delete deleteNode;
    return;
  }
  deleteStudent(studentName, start, current->getNext());
  
}
