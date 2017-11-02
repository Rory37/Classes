#include "classparent.h"

class classmovie : public classparent {
 public:
  ~classmovie();
  virtual void setDirect(char*);
  virtual void setRate(double);
  virtual void setDur(double);

  virtual char* getDirect();
  virtual double getRate();
  virtual double getDur();

  char* director;
  double rating;
  double duration;
};
