#include "classparent"

class classvideo : public classparent{
 public:

  virtual void setPublisher(char*);
  virtual void setRating(double);
  virtual char* getPublisher();
  virtual double getRating();

  char* [80];
  double rating;
};
