#ifndef DSSTRING_H
#define DSSTRING_H
#include "string.h"
#include "catch.hpp"
#include "dsvector.hpp"
#include <fstream>

class DSstring
{
  private:
  char* data;
  int size;

  public:
  //empty constructor
  DSstring();
  //copy constructor
  DSstring(const DSstring&);
  //constructor with a char*
  DSstring(char*);
  //Depunctuator
  void depuncuate(char p[28]);
  //decapitalizer
  void decap(char uppercase[], char lowercase[]);
  //remove
  void remove(int pos);
  //returns char* of string
  char* getString();
  //returns string from start(x) to end(y)
  char* getString(int x, int y);
  //destructor
  ~DSstring();
  // = operator
  DSstring& operator = (const DSstring&);
  //<<
  void output();
  // == operator
  bool operator == (const DSstring&) const;
  bool operator == (const char* arg) const;
  char operator [] (int p);
  //find function
  bool find(DSstring arg);
  //getChar used in find
  char getChar(int pos);
  //get size function
  int getSize();

  };

#endif
