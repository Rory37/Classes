#include <iostream>
#include <cstring>
#include <vector>
#include "classvideo.h"
#include "classmovie.h"
#include "classmusic.h"
#include "classparent.h"

using namespace std;

void add(vector<classparent*>*);
void search(vector<classparent*>*);
void deleting(vector<classparent*>*);

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
    else if (strcmp(com, "SEARCH") == 0){
      search(list);
    }
    else if (strcmp(com, "DELETE") == 0) {
      deleting(list);
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
      cin.ignore();
      med -> setYear(newyear);

      //Gets publisher
      cout << "Please enter the publisher" << endl;
      char* publish = new char [80];
      cin.getline(publish, 80);
      med -> setPublisher(publish);

      //Gets Rating
      cout << "Please enter the rating" << endl;
      double rate;
      cin >> rate;
      cin.ignore();
      med -> setRating(rate);

      cout << "Your addition was successful" << endl;
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
      cin.ignore();
      med -> setYear(newyear);

      //Gets director
      cout << "Please enter the director" << endl;
      char* dir = new char[80];
      cin.getline(dir, 80);
      med -> setDirect(dir);

      //Gets duration
      cout << "Please enter the duration of the movie" << endl;
      double dur;
      cin >> dur;
      cin.ignore();
      med -> setDur(dur);

      //Gets rating
      cout << "Please enter the rating of the movie" << endl;
      double rate;
      cin >> rate;
      cin.ignore();
      med -> setRate(rate);

      cout << "Your addition was successful" << endl;
      
    }
    else if (strcmp(medtyp, "MUSIC") == 0) {
      cormedia = true;
      classmusic* med = new classmusic();
      list -> push_back(med);
      med -> setType(2);

      //Gets title
      cout << "Please enter the title of the song" << endl;
      char* title = new char[80];
      cin.getline(title, 80);
      med -> setTitle(title);
      cout << med -> getTitle() << endl;

      //Gets year
      cout << "Please enter the year it was made" << endl;
      int newyear;
      cin >> newyear;
      cin.ignore();
      med -> setYear(newyear);

      //Gets Artist
      cout << "Please enter the artist of the song" << endl;
      char* art = new char[80];
      cin.getline(art, 80);
      med -> setArtist(art);

      //Sets Publisher
      cout << "Please enter the publisher of the song" << endl;
      char* pub = new char[80];
      cin.getline(pub, 80);
      med -> setPublish(pub);

      //Sets Duration
      cout << "Please enter the duration of the song" << endl;
      double dur;
      cin >> dur;
      cin.ignore();
      med -> setDur(dur);

      cout << "Your addition was successful" << endl;
    }
    else {
      cout << "Please make sure that you enter a valid media" << endl;
    }
  }
  delete list;
}

void search(vector<classparent*>* list) {
  cout << "Do you wish to search by TITLE or YEAR?" << endl;
  char stype[80];
  cin.getline(stype, 80);
  bool val = false;
  while (val == false) {
    
    for (int i = 0; i < strlen(stype); i++) {
      stype[i] = toupper(stype[i]);
    }
    
    if (strcmp(stype, "TITLE") == 0) {
      val = true;
      cout << "Please input the title you are searching for" << endl;
      char search[80];
      cin.getline(search, 80);
      for (vector<classparent*>:: iterator it = list -> begin(); it != list -> end(); ++it) {

	if (strcmp(search, (*it) -> title) == 0) {

	  if (((*it) -> getType()) == 0) {
	    classvideo* newvi = (classvideo*)(*it); //Line by Jason Galbraith
	    cout << "Type: Videogame" << endl;
	    cout << "Title: " << newvi -> getTitle() << endl;
	    cout << "Year: " << newvi -> getYear() << endl;
	    cout << "Publisher: " << newvi -> getPublisher() << endl;
	    cout << "Rating: " << newvi -> getRating() << endl << endl;
	  }
	  else if (((*it) -> getType()) == 1) {
	    classmovie* newmo = (classmovie*)(*it); //Line by Jason Galbraith
	    cout << "Type: Movie" << endl;
	    cout << "Title: " << newmo -> getTitle() << endl;
	    cout << "Year: " << newmo -> getYear() << endl;
	    cout << "Duration: " << newmo -> getDur() << endl;
	    cout << "Rating: " << newmo -> getRate() << endl << endl;
	  }
	  else if (((*it) -> getType()) == 2) {
	    classmusic* newmu = (classmusic*)(*it); //Line from Jason Galbraith
	    cout << "Type: Music" << endl;
	    cout << "Title: " << newmu -> getTitle() << endl;
	    cout << "Year: " << newmu -> getYear() << endl;
	    cout << "Artist: " << newmu -> getArtist() << endl;
	    cout << "Duration: " << newmu -> getDur() << endl;
	    cout << "Publisher: " << newmu -> getPublish() << endl << endl;
	  }
	}
      }
    }
    else if (strcmp(stype, "YEAR") == 0) {
      val = true;
      cout << "Please input the year you are searching for" << endl;
      int y;
      cin >> y;
      cin.ignore();
      for (vector<classparent*>:: iterator it = list -> begin(); it != list -> end(); ++it) {

	if ((*it) -> year == y) {

	  if (((*it) -> getType()) == 0) {
	    classvideo* newvi = (classvideo*)(*it); //Line by Jason Galbraith
	    cout << "Type: Videogame" << endl;
	    cout << "Title: " << newvi -> getTitle() << endl;
	    cout << "Year: " << newvi -> getYear() << endl;
	    cout << "Publisher: " << newvi -> getPublisher() << endl;
	    cout << "Rating: " << newvi -> getRating() << endl << endl;
	  }
	  else if (((*it) -> getType()) == 1) {
	    classmovie* newmo = (classmovie*)(*it); //Line by Jason Galbraith
	    cout << "Type: Movie" << endl;
	    cout << "Title: " << newmo -> getTitle() << endl;
	    cout << "Year: " << newmo -> getYear() << endl;
	    cout << "Duration: " << newmo -> getDur() << endl;
	    cout << "Rating: " << newmo -> getRate() << endl << endl;
	  }
	  else if (((*it) -> getType()) == 2) {
	    classmusic* newmu = (classmusic*)(*it); //Line from Jaso Galbraith
	    cout << "Type: Music" << endl;
	    cout << "Title: " << newmu -> getTitle() << endl;
	    cout << "Year: " << newmu -> getYear() << endl;
	    cout << "Artist: " << newmu -> getArtist() << endl;
	    cout << "Duration: " << newmu -> getDur() << endl;
	    cout << "Publisher: " << newmu -> getPublish() << endl << endl;
	  }
	}
      }
    }
    else {
      cout << "Please put in TITLE or YEAR for search method" << endl;
    }
  }
}

void deleting(vector<classparent*>* list) {
  cout << "Do you wish to search for items to delete by TITLE or YEAR?" << endl;
  char stype[80];
  cin.getline(stype, 80);
  bool val = false;
  while (val == false) {

    for (int i = 0; i < strlen(stype); i++) {
      stype[i] = toupper(stype[i]);
    }

    if (strcmp(stype, "TITLE") == 0) {
      val = true;
      cout << "Please input the title you wish to delete" << endl;
      char search[80];
      cin.getline(search, 80);
      bool ended = false;
      while (ended == false){
	ended = true;
	for (vector<classparent*>:: iterator it = list -> begin(); it != list -> end(); ++it) {
	  
	  if (strcmp(search, (*it) -> title) == 0) {
	    
	    if (((*it) -> getType()) == 0) {
	      classvideo* newvi = (classvideo*)(*it); //Line provided by Jason Galbraith
	      cout << "Type: Videogame" << endl;
	      cout << "Title: " << newvi -> getTitle() << endl;
	      cout << "Year: " << newvi -> getYear() << endl;
	      cout << "Publisher: " << newvi -> getPublisher() << endl;
	      cout << "Rating: " << newvi -> getRating() << endl << endl;
	      cout << "Do you wish to delete this title (y or n)" << endl;
	      char yesno;
	      cin >> yesno;
	      cin.ignore();
	      if (yesno == 'y') {
		delete newvi;
		list -> erase(it);
		ended = false;
		break;
	      }
	    }
	    else if (((*it) -> getType()) == 1) {
	      classmovie* newmo = (classmovie*)(*it); //Line by Jason Galbraith
	      cout << "Type: Movie" << endl;
	      cout << "Title: " << newmo -> getTitle() << endl;
	      cout << "Year: " << newmo -> getYear() << endl;
	      cout << "Duration: " << newmo -> getDur() << endl;
	      cout << "Rating: " << newmo -> getRate() << endl << endl;
	      cout << "Do you wish to delete this title (y or n)" << endl;
	      char yesno;
	      cin >> yesno;
	      cin.ignore();
	      if (yesno == 'y') {
		delete newmo;
		list -> erase(it);
		ended = false;
		break;
	      }
	    }
	    else if (((*it) -> getType()) == 2) {
	      classmusic* newmu = (classmusic*)(*it); //Line from Jason Galbraith
	      cout << "Type: Music" << endl;
	      cout << "Title: " << newmu -> getTitle() << endl;
	      cout << "Year: " << newmu -> getYear() << endl;
	      cout << "Artist: " << newmu -> getArtist() << endl;
	      cout << "Duration: " << newmu -> getDur() << endl;
	      cout << "Publisher: " << newmu -> getPublish() << endl << endl;
	      cout << "Do you wish to delete this title (y or n)" << endl;
	      char yesno;
	      cin >> yesno;
	      cin.ignore();
	      if (yesno == 'y') {
		delete newmu;
		list -> erase(it);
		ended = false;
		break;
	      }
	    }
	  }
	}
      }
    }
    else if (strcmp(stype, "YEAR") == 0) {
      val = true;
      cout << "Please input the year you are searching for" << endl;
      int y;
      cin >> y;
      cin.ignore();
      bool ended = false;
      while (ended == false) {
	ended = true;
	for (vector<classparent*>:: iterator it = list -> begin(); it != list -> end(); ++it) {
	  
	  if ((*it) -> year == y) {
	    if (((*it) -> getType()) == 0) {
	      classvideo* newvi = (classvideo*)(*it); //Line by Jason Galbraith
	      cout << "Type: Videogame" << endl;
	      cout << "Title: " << newvi -> getTitle() << endl;
	      cout << "Year: " << newvi -> getYear() << endl;
	      cout << "Publisher: " << newvi -> getPublisher() << endl;
	      cout << "Rating: " << newvi -> getRating() << endl << endl;
	      cout << "Do you wish to delete this title (y or n)" << endl;
	      char yesno;
	      cin >> yesno;
	      cin.ignore();
	      if (yesno == 'y') {
		delete newvi;
		list -> erase(it);
		ended = false;
		break;
	      }
	    }
	    else if (((*it) -> getType()) == 1) {
	      classmovie* newmo = (classmovie*)(*it); //Line by Jason Galbraith
	      cout << "Type: Movie" << endl;
	      cout << "Title: " << newmo -> getTitle() << endl;
	      cout << "Year: " << newmo -> getYear() << endl;
	      cout << "Duration: " << newmo -> getDur() << endl;
	      cout << "Rating: " << newmo -> getRate() << endl << endl;
	      cout << "Do you wish to delete this title (y or n)" << endl;
	      char yesno;
	      cin >> yesno;
	      cin.ignore();
	      if (yesno == 'y') {
		delete newmo;
		list -> erase(it);
		ended = false;
		break;
	      }
	    }
	    else if (((*it) -> getType()) == 2) {
	      classmusic* newmu = (classmusic*)(*it); //Line from Jason Galbraith
	      cout << "Type: Music" << endl;
	      cout << "Title: " << newmu -> getTitle() << endl;
	      cout << "Year: " << newmu -> getYear() << endl;
	      cout << "Artist: " << newmu -> getArtist() << endl;
	      cout << "Duration: " << newmu -> getDur() << endl;
	      cout << "Publisher: " << newmu -> getPublish() << endl << endl;
	      cout << "Do you wish to delete this title (y or n)" << endl;
	      char yesno;
	      cin >> yesno;
	      cin.ignore();
	      if (yesno == 'y') {
		delete newmu;
		list -> erase(it);
		ended = false;
		break;
	      }
	    }
	  }
	}
      }
    }
    else {
      cout << "Please put in TITLE or YEAR for search method" << endl;
    }
  }
}
