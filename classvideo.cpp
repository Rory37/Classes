#include <iostream>
#include "classvideo.h"
#include <cstring>
using namespace std;

void classvideo :: setPublisher (char* newPub) {
  publisher = new char[80];
  strcpy(publisher, newPub);
}

char* classvideo :: getPublisher () {
  return publisher;
}

void classvideo :: setRating (double newRate) {
  rating = newRate;
}

double classvideo :: getRating () {
  return rating;
}
