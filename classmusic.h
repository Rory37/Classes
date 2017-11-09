#include "classparent.h" //sets up inheretence

class classmusic : public classparent {//sets up inheretence
 public:
  ~classmusic(); //destructor
 //Sets all the virtual methods (virtual lets it overide the parent class)
  virtual void setArtist(char*); //function to set artist
  virtual void setPublish(char*);//function to set publisher
  virtual void setDur(double); // function to set duration
  
  virtual char* getArtist(); //function to return artist
  virtual char* getPublish();//function to return publisher
  virtual double getDur(); //function to return duration

  char* artist;//pointer to array to store artist
  char* publisher;//pointer to array to store publisher
  double duration;//double to store duration
};
