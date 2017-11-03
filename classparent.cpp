#include <iostream>
#include "classparent.h"
#include <cstring>//for strcmp
using namespace std;

classparent :: ~classparent() {//destructor destroys string pointer
  delete title;
}

void classparent::setType(int newType) {//sets the type (in terms of int)
  type = newType;
}

int classparent::getType() {//returns the type
  return type;
}

void classparent::setTitle(char* newTitle) { //sets the title
  title = new char[80];
  strcpy(title,newTitle);
}

char* classparent::getTitle() {//returns the title
  return title;
}

void classparent::setYear(int newYear) {//sets the year
  year = newYear;
}

int classparent::getYear() { // returns the year
  return year;
}
