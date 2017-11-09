#include "classparent.h"

class classvideo : public classparent{//setts as child
 public:
  ~classvideo();//destructor
 //Sets all the virtual methods (virtual lets it overide the parent class)
  virtual void setPublisher(char*);//Function to set publisher
  virtual void setRating(double);//Function to set rating
  virtual char* getPublisher();//Function to return publisher
  virtual double getRating();//Function to return rating

  char* publisher;//pointer to array to store publisher
  double rating;//double to store rating
};
