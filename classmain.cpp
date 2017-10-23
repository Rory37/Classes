#include <iostream>
#include <cstring>
#include <vector>
#include "parent.h"

void add(vector<parent*>*);


using namespace std;

int main() {
  vector<parent*>* list = new vector<parent*>();
  bool running = true;
  cout << "This is the media database." << endl;
  cout << "Please enter an operation (ADD, SEARCH, DELETE)" << endl;
  char com[80];
  cin.getline(com, 80);

  for (int i = 0; i < strlen(com); i++) {
   com[i] = toupper(com[i]);
  }
  
  if (strcmp(com, "ADD")) == 0) {
    add(list);
  }

}
void add(vector<parent*>* list) {
  bool cormedia = false;
  while (cormedia == false) {
    cout << "Enter what type of media is to be added (VIDEOGAME, MOVIE, MUSIC)" << endl;
    char medtyp[80];
    int type = -1;

    for (int i = 0; i < strlen(medtyp); i++) {
      com[i] = toupper(medtyp[i]);
    }

    if (strcmp(medtyp, "VIDEOGAME") == 0) {
      type = 0;
      cormedia = true;
      classvideo* vidgame = new classvideo();
      list -> push_back(vidgame);
      vidgame -> setType(1);
    }
    else if (strcmp(medtyp, "MOVIE") == 0) {
      type = 1;
      cormedia = true;
      classmovie* mov = new classmovie();
      list -> push_back(mov);
      movie -> setType(1);
    }
    else if (strcmp(medtyp, "MUSIC") == 0) {
      type = 2;
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
