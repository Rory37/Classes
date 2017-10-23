class classparent {
 public:
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
