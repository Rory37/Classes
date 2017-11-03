#include <iostream>
#include "classvideo.h"
#include <cstring>
using namespace std;//needed for strcmp

classvideo :: ~classvideo(){//destructor of char pointer
  delete publisher;
}
  
void classvideo :: setPublisher (char* newPub) {//sets publisher
  publisher = new char[80];
  strcpy(publisher, newPub);
}

char* classvideo :: getPublisher () {//returns publisher
  return publisher;
}

void classvideo :: setRating (double newRate) {//sets rating
  rating = newRate;
}

double classvideo :: getRating () {//returns rating
  return rating;
}
