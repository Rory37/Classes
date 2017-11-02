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
  vector<classparent*>* list = new vector<classparent*>(); //Creates vector
  bool running = true; //Bool for loop for program to keep running
  cout << "This is the media database." << endl;
  while (running == true) { //When false, runs off end of program 
    cout << "Please enter an operation (ADD, SEARCH, DELETE, QUIT)" << endl;
    char com[80];
    cin.getline(com, 80); //Gets input
    
    for (int i = 0; i < strlen(com); i++) { //Makes everything uppercase to avoid being case sensitive
      com[i] = toupper(com[i]);
    }
    
    if (strcmp(com, "ADD") == 0) {
      add(list); //Runs add code
    }
    else if (strcmp(com, "SEARCH") == 0){
      search(list); //Runs search code
    }
    else if (strcmp(com, "DELETE") == 0) {
      deleting(list); //Runs delete code
    }
    else if (strcmp(com, "QUIT") == 0) {
      running = false; // Makes the loop end
    }
    else {
      cout << "Please make sure your input is valid" << endl;
    }
  }
  delete list; //Deletes list when program ends
}
void add(vector<classparent*>* list) {
  bool cormedia = false;
  while (cormedia == false) { //Runs until correct media type is entered
    cout << "Enter what type of media is to be added (VIDEOGAME, MOVIE, MUSIC)" << endl;
    char medtyp[80];
    cin.getline(medtyp, 80); //Takes in input
    for (int i = 0; i < strlen(medtyp); i++) {//Puts all to upper case
      medtyp[i] = toupper(medtyp[i]);
    }

    if (strcmp(medtyp, "VIDEOGAME") == 0) { //If video game
      cormedia = true;
      classvideo* med = new classvideo(); //creates a new video game object
      list -> push_back(med); //puts this into vector
      med -> setType(0); //defines as videogame for later check (see classparent)

      //Gets title
      cout << "Please enter the title" << endl;
      char* title = new char [80];
      cin.getline(title, 80); //assigns what title should point to 
      med -> setTitle(title); //Sets the title to be later accessed (see classparent)

      //Gets year
      cout << "Please enter the year it was made" << endl;
      int newyear;
      cin >> newyear;
      cin.ignore(); //clears console input to not mess with later cin.getline
      med -> setYear(newyear); //Sets the year (see classparent)

      //Gets publisher
      cout << "Please enter the publisher" << endl;
      char* publish = new char [80];
      cin.getline(publish, 80);
      med -> setPublisher(publish); //Sets publisher (in classvideo)

      //Gets Rating
      cout << "Please enter the rating" << endl;
      double rate;
      cin >> rate;
      cin.ignore(); //ignores to not mess with cin.getline
      med -> setRating(rate);//Sets rate (in classvideo)

      cout << "Your addition was successful" << endl;
    }
    else if (strcmp(medtyp, "MOVIE") == 0) { //If input movie
      cormedia = true;
      classmovie* med = new classmovie(); //Creates new pointer to a classmovie object
      list -> push_back(med);//Adds to vector
      med -> setType(1); // Defines as move (classparent)

      //Gets title
      cout << "Please enter the title" << endl;
      char* title = new char[80];
      cin.getline(title, 80);
      med -> setTitle(title); //Sets title (see classparent)

      //Gets year
      cout << "Please enter the year it was made" << endl;
      int newyear;
      cin >> newyear;
      cin.ignore(); //ignores to prevent later cin.getline issues
      med -> setYear(newyear); //Sets year (classparent)

      //Gets director
      cout << "Please enter the director" << endl;
      char* dir = new char[80];
      cin.getline(dir, 80);
      med -> setDirect(dir); //Sets director (classmovie)

      //Gets duration
      cout << "Please enter the duration of the movie" << endl;
      double dur;
      cin >> dur;
      cin.ignore();//Clears cin
      med -> setDur(dur);//Sets duration (classmovie)

      //Gets rating
      cout << "Please enter the rating of the movie" << endl;
      double rate;
      cin >> rate;
      cin.ignore(); // clears cin
      med -> setRate(rate); //Sets rating (classmovie)

      cout << "Your addition was successful" << endl;
      
    }
    else if (strcmp(medtyp, "MUSIC") == 0) { //If input music
      cormedia = true;
      classmusic* med = new classmusic(); //Defines pointer to a classmusic type
      list -> push_back(med);//adds to parent class vector
      med -> setType(2);//Defines as music (classparent)

      //Gets title
      cout << "Please enter the title of the song" << endl;
      char* title = new char[80];
      cin.getline(title, 80);
      med -> setTitle(title); //Sets title by passing pointer (classparent)

      //Gets year
      cout << "Please enter the year it was made" << endl;
      int newyear;
      cin >> newyear;
      cin.ignore(); //clears cin
      med -> setYear(newyear); // Sets year (classparent)

      //Gets Artist
      cout << "Please enter the artist of the song" << endl;
      char* art = new char[80];
      cin.getline(art, 80); 
      med -> setArtist(art);//Sets artist pointer(classmusic)

      //Sets Publisher
      cout << "Please enter the publisher of the song" << endl;
      char* pub = new char[80];
      cin.getline(pub, 80);
      med -> setPublish(pub); //Sets publisher pointer (classmusic)

      //Sets Duration
      cout << "Please enter the duration of the song" << endl;
      double dur;
      cin >> dur;
      cin.ignore(); //clear cin
      med -> setDur(dur); // Sets duration (classmusic)

      cout << "Your addition was successful" << endl;
    }
    else { //If none of said types
      cout << "Please make sure that you enter a valid media" << endl;
    }
  }
}

void search(vector<classparent*>* list) {
  cout << "Do you wish to search by TITLE or YEAR?" << endl;
  char stype[80];
  cin.getline(stype, 80);
  bool val = false;
  while (val == false) { //prevents inputting not title or year
    
    for (int i = 0; i < strlen(stype); i++) {
      stype[i] = toupper(stype[i]); //puts all to uppercase
    }
    
    if (strcmp(stype, "TITLE") == 0) {
      val = true;
      cout << "Please input the title you are searching for" << endl;
      char search[80];
      cin.getline(search, 80); //Records what to search for
      for (vector<classparent*>:: iterator it = list -> begin(); it != list -> end(); ++it) { //Creates iterator for vector

	if (strcmp(search, (*it) -> title) == 0) { //If the term matches titles

	  if (((*it) -> getType()) == 0) {//if video game
	    classvideo* newvi = (classvideo*)(*it); //Line by Jason Galbraith;Defines as a video type
	    //Prints all info on term
            cout << "Type: Videogame" << endl;
	    cout << "Title: " << newvi -> getTitle() << endl;
	    cout << "Year: " << newvi -> getYear() << endl;
	    cout << "Publisher: " << newvi -> getPublisher() << endl;
	    cout << "Rating: " << newvi -> getRating() << endl << endl;
	  }
	  else if (((*it) -> getType()) == 1) {//if movie
	    classmovie* newmo = (classmovie*)(*it); //Line by Jason Galbraith;defines as movie
	    //Prints all info
	    cout << "Type: Movie" << endl;
	    cout << "Title: " << newmo -> getTitle() << endl;
	    cout << "Year: " << newmo -> getYear() << endl;
	    cout << "Duration: " << newmo -> getDur() << endl;
	    cout << "Rating: " << newmo -> getRate() << endl << endl;
	  }
	  else if (((*it) -> getType()) == 2) { //if music
	    classmusic* newmu = (classmusic*)(*it); //Line from Jason Galbraith; defines as music
	    //Prints all info
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
    else if (strcmp(stype, "YEAR") == 0) { //if searching by year
      val = true;//ends loop
      cout << "Please input the year you are searching for" << endl;
      int y;
      cin >> y;
      cin.ignore(); //clears cin
      for (vector<classparent*>:: iterator it = list -> begin(); it != list -> end(); ++it) {//makes iterator for vector

	if ((*it) -> year == y) {

	  if (((*it) -> getType()) == 0) { //videogame
	    classvideo* newvi = (classvideo*)(*it); //Line by Jason Galbraith
            //prints all info
            cout << "Type: Videogame" << endl;
	    cout << "Title: " << newvi -> getTitle() << endl;
	    cout << "Year: " << newvi -> getYear() << endl;
	    cout << "Publisher: " << newvi -> getPublisher() << endl;
	    cout << "Rating: " << newvi -> getRating() << endl << endl;
	  }
	  else if (((*it) -> getType()) == 1) {//movie
	    classmovie* newmo = (classmovie*)(*it); //Line by Jason Galbraith
	    //Prints info
	    cout << "Type: Movie" << endl;
	    cout << "Title: " << newmo -> getTitle() << endl;
	    cout << "Year: " << newmo -> getYear() << endl;
	    cout << "Duration: " << newmo -> getDur() << endl;
	    cout << "Rating: " << newmo -> getRate() << endl << endl;
	  }
	  else if (((*it) -> getType()) == 2) {//music
	    classmusic* newmu = (classmusic*)(*it); //Line from Jaso Galbraith
	    //Prints info
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

void deleting(vector<classparent*>* list) {//passes in vector pointer to work on
  cout << "Do you wish to search for items to delete by TITLE or YEAR?" << endl;//uses search code to find the items to delete
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
      bool ended = false;//To reset iterator once item is deleted
      while (ended == false){
	ended = true;//Sets to true, but if something is deleted it goes to false; to leave while, nothing is deleted
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
	      if (yesno == 'y') {//if they say yes
		delete newvi; //deletes all contents of object(not just pointer
		list -> erase(it);//remove from vector
		ended = false;
		break; //leave iterator
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
		delete newmo; //deletes content of movie
		list -> erase(it); //removes from vector
		ended = false;
		break;//exits iterator
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
		delete newmu;//deletes items in music
		list -> erase(it);//remove from vector
		ended = false;
		break;//exits iterator
	      }
	    }
	  }
	}
      }
    }
    else if (strcmp(stype, "YEAR") == 0) {//if by year
      val = true;
      cout << "Please input the year you are searching for" << endl;
      int y;
      cin >> y;
      cin.ignore();//clears cin
      bool ended = false;
      while (ended == false) {
	ended = true;
	for (vector<classparent*>:: iterator it = list -> begin(); it != list -> end(); ++it) {//makes iterator vector
	  
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
		delete newvi;//deletes video
		list -> erase(it);//removes from vector
		ended = false;
		break;//exits iterator
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
		delete newmo;//deletes all stuff in movie
		list -> erase(it);//removes from vector
		ended = false;
		break;//breaks from iterator
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
		delete newmu;//deletes music
		list -> erase(it);//removes from vector
		ended = false;
		break;//exits iterator
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
