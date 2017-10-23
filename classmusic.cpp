#include <iostream>
#include "classmusic.h"
#include <cstring>
using namespace std;

void classmusic :: setArtist(char* newArt) {
  strcpy(artist, newArt);
}

char* classmusic :: getArtist() {
  return artist;
}

void classmusic :: setPublish(char* newPub) {
  strcpy(publisher, newPub);
}

char* classmusic :: getPublish() {
  return publisher;
}

void classmusic :: setDur(double newDur) {
  duration = newDur;
}

double classmusic :: getDur() {
  return duration;
}
