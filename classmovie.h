#include "classparent.h" //Sets up inheritence

class classmovie : public classparent {//sets as child class
 public:
  ~classmovie(); //destructor
 //Sets all the virtual methods (virt
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
