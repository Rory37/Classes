#ifndef guard //Note: This guard code is based on wikipedia's Include_Guard page ; The guard is needed to prevent multiple inclusions causing issue
#define guard

class classparent {
 public:
  ~classparent();//destructor
  virtual void setType(int);//Function to define the type of media (in terms of int)
  virtual void setTitle(char*);//Function to set title
  virtual void setYear(int);//Function to set year
  virtual int getType();//Function to return type
  virtual char* getTitle();//Function to return title
  virtual int getYear();//Function to return year
  int year;//int to store year
  char* title;//pointer to array to store title
  int type;//Int to store type
};

#endif//Ends include guard
