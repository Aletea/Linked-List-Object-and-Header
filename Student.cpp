#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

Student::Student(char* fN, char* lN, int Identify, double GP) {
  firstName = fN;
  lastName = lN;
  ID = Identify;
  GPA = GP;
}

Student::~Student() {
  delete firstName;
  delete lastName;
}

char* Student::getName() {
  char* fullName = new char[80];
  strcpy(fullName, firstName);
  fullName[strlen(fullName)] = ' ';
  int count = 0;
  for (int i = strlen(fullName); i < strlen(fullName) + strlen(lastName); i++) {
    fullName[i] = lastName[count];
    count++;
  }
  fullName[strlen(fullName)] = '\0';
  return fullName;
}

int Student::getID() {
  return ID;
  
}

double Student::getGPA() {
  return GPA;
}
