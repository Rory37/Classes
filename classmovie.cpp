#include <iostream>
#include "classmovie.h"
#include <cstring>
using namespace std;

classmovie :: ~classmovie() {
  delete director; 
}

void classmovie :: setDirect(char* newDir) {
  director = new char[80];
  strcpy(director, newDir);
}

char* classmovie :: getDirect() {
  return director;
}

void classmovie :: setDur(double newDur ) {
  duration = newDur;
}

double classmovie :: getDur() {
  return duration;
}

void classmovie :: setRate(double newRate) {
  rating = newRate;
}

double classmovie :: getRate() {
  return rating;
}
