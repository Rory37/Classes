#include "classparent.h"

class classvideo : public classparent{
 public:
  ~classvideo();
  virtual void setPublisher(char*);
  virtual void setRating(double);
  virtual char* getPublisher();
  virtual double getRating();

  char* publisher;
  double rating;
};
