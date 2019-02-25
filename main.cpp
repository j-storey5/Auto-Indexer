#define CATCH_CONFIG_RUNNER
#include <iostream>
#include <fstream>
#include "catch.hpp"
#include "dsstring.h"
#include "dsvector.hpp"

using namespace std;


//runs catch
int runCatchTest(int argc, char* const argv[4])
{
    return Catch::Session().run();
}


int main(int argc, char* const argv[4])
{
  bool test = true;
          ;
  if (argc != 1)
  {
      test = false;
  }
  if (test)
  {
      return runCatchTest(argc,argv);
  }
  else
  {
    char punct[29] = {'!','!','@','#','$','%','^','&','*','(','(',')','_','-','+','=','{','}','[',']',':',';','"','<',',','>','.','?','/'};
    char uppercase[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char lowercase[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    ifstream infile;
    infile.open(argv[1]);
    ofstream outfile;
    outfile.open(argv[2]);
    char a[80];
    DSvector <DSstring>words;
    while (infile)
    {
        //read in word
    infile.getline(a,80, ' ');
    DSstring candidate(a);
    //normalize
    candidate.depuncuate(punct);
    candidate.decap(uppercase,lowercase);
    //if !found add to vector
    if(!words.found(candidate))
    {
        words.push_back(candidate);
    }

    }
    infile.close();
    //output file
    for(int i = 0;  i < words.getSize(); i++)
    {
        outfile<<words[i].getString();
        outfile<<std::endl;

    }

    return 0;
   }
}
