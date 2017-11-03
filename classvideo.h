#include "classparent.h"

class classvideo : public classparent{//setts as child
 public:
  ~classvideo();//destructor
  virtual void setPublisher(char*);
  virtual void setRating(double);
  virtual char* getPublisher();
  virtual double getRating();

  char* publisher;
  double rating;
};
