#ifndef guard //Note: This guard code is based on wikipedia's Include_Guard page ; The guard is needed to prevent multiple inclusions causing issue
#define guard

class classparent {
 public:
  ~classparent();//destructor
  virtual void setType(int);
  virtual void setTitle(char*);
  virtual void setYear(int);
  virtual int getType();
  virtual char* getTitle();
  virtual int getYear();
  int year;
  char* title;
  int type;
};

#endif
