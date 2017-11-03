#include <iostream>
#include "classmusic.h"
#include <cstring> //for strcmp
using namespace std;

classmusic :: ~classmusic() {//destructor for char pointer
  delete artist;
  delete publisher;
}

void classmusic :: setArtist(char* newArt) {//sets the artist
  artist = new char[80];
  strcpy(artist, newArt);
}

char* classmusic :: getArtist() { //returns the artist
  return artist;
}

void classmusic :: setPublish(char* newPub) {//sets the publisher
  publisher = new char[80];
  strcpy(publisher, newPub);
}

char* classmusic :: getPublish() {//returns publisher
  return publisher;
}

void classmusic :: setDur(double newDur) { //sets duration
  duration = newDur;
}

double classmusic :: getDur() {//returns duration
  return duration;
}
