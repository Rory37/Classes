#include <iostream>
#include "classmovie.h"
#include <cstring>
using namespace std;

classmovie :: ~classmovie() {//destructor
  delete director; 
}

void classmovie :: setDirect(char* newDir) { //sets the director pointer
  director = new char[80];
  strcpy(director, newDir);
}

char* classmovie :: getDirect() { //returns the director pointer
  return director;
}

void classmovie :: setDur(double newDur ) { //sets the duration
  duration = newDur;
}

double classmovie :: getDur() {//returns
  return duration;
}

void classmovie :: setRate(double newRate) {
  rating = newRate;
}

double classmovie :: getRate() {
  return rating;
}
