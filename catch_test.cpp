#include "catch.hpp"

#include <cstring>
#include "dsstring.h"
#include "dsvector.hpp"
#include <iostream>


TEST_CASE("String class")
{
    DSstring name = "Jack";
    DSstring name2 = name;

    SECTION ("GETTERS")
    {
        REQUIRE(name.getChar(0) == 'J');
        REQUIRE(name.getChar(3) == 'k');
        REQUIRE(name.getSize() == 4);
    }

    SECTION ("==")
    {
        REQUIRE(name == name2);
    }

    SECTION("Decapitalizer and Depunctuator")
    {
        char punct[28] = {'!','@','#','$','%','^','&','*','(','(',')','_','-','+','=','{','}','[',']',':',';','"','<',',','>','.','?','/'};
        char uppercase[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
        char lowercase[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        DSstring q = "QUE$S^T*ION";
        q.depuncuate(punct);
        q.decap(uppercase,lowercase);
        REQUIRE(q == "question");
    }
 }
TEST_CASE("Vector Class")
{
    DSvector<int> check;
    DSvector<DSstring> str_check;

    DSstring f1 = "taco";
    check.push_back(1);
    str_check.push_back(f1);

    DSstring f2 = "fishsticks";
    check.push_back(2);
    str_check.push_back(f2);

    DSstring f3 = "burger";
    check.push_back(3);
    str_check.push_back(f3);

    DSstring f4 = "Chicken Strips";
    check.push_back(4);
    str_check.push_back(f4);

    SECTION("Size and capacity")
    {
        REQUIRE(check.getSize() == 4);
        REQUIRE(check.getCapacity() == 10);
        REQUIRE(str_check.getSize() == 4);
        REQUIRE(str_check.getCapacity()==10);
    }

    SECTION("[] operator")
    {
        REQUIRE(check[0] == 1);
        REQUIRE(str_check[0]=="taco");
    }
    SECTION("Insert/Swap/Remove")
    {
       DSstring test_in = "test";
       check.insert(10,2);
       str_check.insert(test_in,2);
       REQUIRE(check.getSize() == 5);
       REQUIRE(str_check.getSize()==5);
       REQUIRE(check[2] == 10);
       REQUIRE(str_check[2] == "test");
       //write a << operator for an fstream with a dsstring
       check.swapPos(2,3);
       str_check.swapPos(2,3);
       REQUIRE(check[3]==10);
       REQUIRE(str_check[3]=="test");
       check.remove(3);
       str_check.remove(3);
       REQUIRE(check.getSize()==4);
       REQUIRE(check[3] == 4);
       REQUIRE(str_check.getSize()==4);
       REQUIRE(str_check[2]=="burger");
       str_check.slide(test_in,1);
       REQUIRE(str_check.getSize() == 5);
       REQUIRE(str_check[0] == "taco");
       REQUIRE(str_check[1] == "test");
       REQUIRE(str_check[2] == "fishsticks");


    }
    SECTION(" vector find function ")
    {

       REQUIRE(str_check.found(f1) == true);
       str_check.remove(0);
       REQUIRE(str_check.found(f1)==false);
    }
}
