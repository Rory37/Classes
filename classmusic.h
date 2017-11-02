#include "classparent.h"

class classmusic : public classparent {
 public:
  ~classmusic();
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
