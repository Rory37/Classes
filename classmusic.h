#include "classparent.h" //sets up inheretence

class classmusic : public classparent {//sets up inheretence
 public:
  ~classmusic(); //destructor
  virtual void setArtist(char*);
  virtual void setPublish(char*);
  virtual void setDur(double);
  
  virtual char* getArtist();
  virtual char* getPublish();
  virtual double getDur();

  char* artist;
  char* publisher;
  double duration;
};
