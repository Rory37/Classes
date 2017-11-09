#include "classparent.h" //Sets up inheritence

class classmovie : public classparent {//sets as child class
 public:
  ~classmovie(); //destructor
 //Sets all the virtual methods (virtual lets it overide the parent class)
  virtual void setDirect(char*);//declares funtion to set the director
  virtual void setRate(double);//declares function to set rating
  virtual void setDur(double);//declares function to set duration

  virtual char* getDirect();//function to return director
  virtual double getRate();//function to return rating
  virtual double getDur();//function to return duration

  char* director; //pointer to array to store director
  double rating;//double to store rating
  double duration;//double to store duration
};
