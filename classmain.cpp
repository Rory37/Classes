#include <iostream>
#include <cstring>
#include <vector>
#include "classvideo.h"
#include "classmovie.h"
#include "classmusic.h"
#include "classparent.h"

using namespace std;

void add(vector<classparent*>*);


int main() {
  vector<classparent*>* list = new vector<classparent*>();
  bool running = true;
  cout << "This is the media database." << endl;
  cout << "Please enter an operation (ADD, SEARCH, DELETE)" << endl;
  char com[80];
  cin.getline(com, 80);

  for (int i = 0; i < strlen(com); i++) {
    com[i] = toupper(com[i]);
  }

  if (strcmp(com, "ADD") == 0) {
  add(list);
}

}
void add(vector<classparent*>* list) {
  bool cormedia = false;
  while (cormedia == false) {
    cout << "Enter what type of media is to be added (VIDEOGAME, MOVIE, MUSIC)" << endl;
    char medtyp[80];
    int type = -1;

    for (int i = 0; i < strlen(medtyp); i++) {
      medtyp[i] = toupper(medtyp[i]);
    }

    if (strcmp(medtyp, "VIDEOGAME") == 0) {
      cormedia = true;
      classvideo* vidgame = new classvideo();
      list -> push_back(vidgame);
      vidgame -> setType(0);
    }
    else if (strcmp(medtyp, "MOVIE") == 0) {
      cormedia = true;
      classmovie* mov = new classmovie();
      list -> push_back(mov);
      mov -> setType(1);
    }
    else if (strcmp(medtyp, "MUSIC") == 0) {
      cormedia = true;
      classmusic* music = new classmusic();
      list -> push_back(music);
      music -> setType(2);
    }
    else {
      cout << "Please make sure that you enter a valid media" << endl;
    }
  }
  //Gets title
  cout << "Please enter the title" << endl;
  char titlenew [80];
  cin.getline(titlenew, 80);
  
}
