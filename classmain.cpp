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
  while (running == true) {
    cout << "Please enter an operation (ADD, SEARCH, DELETE, QUIT)" << endl;
    char com[80];
    cin.getline(com, 80);
    
    for (int i = 0; i < strlen(com); i++) {
      com[i] = toupper(com[i]);
    }
    
    if (strcmp(com, "ADD") == 0) {
      add(list);
    }
    else if (strcmp(com, "QUIT") == 0) {
      running = false;
    }
    else {
      cout << "Please make sure your input is valid" << endl;
    }
  }
}
void add(vector<classparent*>* list) {
  bool cormedia = false;
  while (cormedia == false) {
    cout << "Enter what type of media is to be added (VIDEOGAME, MOVIE, MUSIC)" << endl;
    char medtyp[80];
    cin.getline(medtyp, 80);
    for (int i = 0; i < strlen(medtyp); i++) {
      medtyp[i] = toupper(medtyp[i]);
    }

    if (strcmp(medtyp, "VIDEOGAME") == 0) {
      cormedia = true;
      classvideo* med = new classvideo();
      list -> push_back(med);
      med -> setType(0);

      //Gets title
      cout << "Please enter the title" << endl;
      char* title = new char [80];
      cin.getline(title, 80);
      med -> setTitle(title);
      cout << med -> getTitle() << endl;

      //Gets year
      cout << "Please enter the year it was made" << endl;
      int newyear;
      cin >> newyear;
      med -> setYear(newyear);
    }
    else if (strcmp(medtyp, "MOVIE") == 0) {
      cormedia = true;
      classmovie* med = new classmovie();
      list -> push_back(med);
      med -> setType(1);

      //Gets title
      cout << "Please enter the title" << endl;
      char* title = new char[80];
      cin.getline(title, 80);
      med -> setTitle(title);
      cout << med -> getTitle() << endl;

      //Gets year
      cout << "Please enter the year it was made" << endl;
      int newyear;
      cin >> newyear;
      med -> setYear(newyear);
    }
    else if (strcmp(medtyp, "MUSIC") == 0) {
      cormedia = true;
      classmusic* med = new classmusic();
      list -> push_back(med);
      med -> setType(2);

      //Gets title
      cout << "Please enter the title" << endl;
      char* title = new char[80];
      cin.getline(title, 80);
      med -> setTitle(title);
      cout << med -> getTitle() << endl;

      //Gets year                                                                                                                                                           cout << "Please enter the year it was made" << endl;
      int newyear;
      cin >> newyear;
      med -> setYear(newyear);
    }
    else {
      cout << "Please make sure that you enter a valid media" << endl;
    }
  }
}
