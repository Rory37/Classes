#include <iostream>
#include "classparent.h"
#include <cstring>
using namespace std;

void classparent::setType(int newType) {
  type = newType;
}

int classparent::getType() {
  return type;
}

void classparent::setTitle(char* newTitle) {
  strcpy(title,newTitle);
}

char [80] classparent::getTitle() {
  return title;
}

void classparent::setYear(int newYear) {
  year = newYear;
}

int classparent::getYear() {
  return year;
}
