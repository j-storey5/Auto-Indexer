#include "dsstring.h"
#include <iostream>

DSstring::DSstring()
{
  data = new char[1];
  data[0] = '\0';
  size = 0;
}

DSstring::DSstring(const DSstring& arg)
{
  data = new char[arg.size + 1];
  strcpy(data, arg.data);
  size = arg.size;
}

DSstring::DSstring(char* text)
{
  int x = 0;
  while (text[x] != '\0')
  {
    x++;
  }
  data = new char[x+1];
  strcpy(data, text);
  size = x;
}

DSstring:: ~DSstring()
{
  //destructor
  delete[]  data;
}


//copy constructor
DSstring& DSstring::operator=(const DSstring & arg)
{
  if(this != &arg)
  {
  //copies the contents of one object into another
  delete [] data; //deletes data from the invoking object
  data = new char[arg.size + 1];
  strcpy(data, arg.data);
  size = arg.size;
  return *this; //returning by value would create a copy, reference works far more efficiently - use refereence unless there is a reason not to
  }
}
//removes a character from the string
void DSstring::remove(int pos)
{
    for(int i = pos; i < size; i++)
    {
       data[pos] = data[pos+1];
    }
    size--;
}


bool DSstring::operator == (const DSstring& arg) const
{
    int x = strcmp(data, arg.data);
    if(x == 0)
    {
        return true;
    }
    return false;
}

bool DSstring::operator == (const char* arg) const
{
    return strcmp(data,arg) == 0;
}


//getters
char* DSstring::getString()
{
  return data;
}

/*
char* DSstring::getString(int x, int y)
{
  char* temp = new char[y-x];
  for(int i = 0; i < size; i++)
  {
     temp[i] = data[x];
     x++;
  }
}
*/
//decapitalize function, takes upper and lowercase alphabets and replaces uppercase letters with lowercase ones
void DSstring::decap(char uppercase[], char lowercase[])
{
    for (int i = 0; i < size; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            if(data[i] == uppercase[j])
            {
                data[i] = lowercase[j];
            }
        }
    }
}

//takes a string and removes any punctuation
void DSstring::depuncuate(char p[29])
{
    int tempsize = size;
    for (int i = 0; i < tempsize; i++)
    {
        for(int j = 0; j < 29; j++)
        {
            if(data[i] == p[j])
            {
                int pos = i;
                for(int i = pos; i < size; i++)
                {
                   data[i] = data[i+1];
                }
                size--;
                break;
            }
        }
    }

}
void DSstring::output()
{
    std::ofstream outfile;
    outfile.open("output.txt");
    for(int i=0; i < size; i++)
    {
        outfile<<data[i];
    }
    for(int i=0; i < size; i++)
    {
        std::cout<<data[i];
    }
}

char DSstring::operator[] (int p)
{
    return data[p];
}
char DSstring::getChar(int pos)
{
  return data[pos];
}

int DSstring::getSize()
{
  return size;
}





/*
//find function takes 2 DSstrings
bool DSstring::find(DSstring arg)
{
  //loops through the string to be searched
  for (int i = 0; i < size; i++)
  {
    if (arg.getChar(0)==data[i])
    {
      //loops through looking for the next character after the first is found
      for(int j = 1; j < arg.getSize(); j++)
      {
        //not found
        if ((arg.getChar(j) != data[j+i]))
        {
          return false;
        }
        //found
        if (arg.getChar(arg.getSize()-1) == data[j+i])
        {
          return true;
        }
      }
    }
  }
  return false;
}
*/
