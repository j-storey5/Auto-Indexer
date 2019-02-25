#ifndef DSVECTOR_H
#define DSVECTOR_H
#include <iostream>
#include "dsstring.h"

template <class t>
class DSvector
{
private:
    //content of vector
    t* data;
    //size of things in vector
    int size;
    //total capacity of the vector
    int capacity;
    //resize member function, inaccessible out of class
    void resize()
    {
        t* temp = new t[size];
        for (int i = 0; i < size; i++)
        {
            temp[i] = data[i];
        }
        capacity = capacity + 10;
        delete[] data;
        data = new t[capacity];
        for (int i = 0; i < size; i++)
        {
            data[i] = temp[i];
        }
        delete[] temp;
    }
public:
    //constructor
    DSvector()
    {
        data = new t[10];
        size = 0;
        capacity = 10;
    }

    //copy constructor
    DSvector(const DSvector<t>& clone)
    {
     capacity = clone.capacity;
     size = clone.size;
     for(int i = 0; i < size; i++)
     {
         data[i] = clone.data[i];
     }
    }

    //destructor
    //template <class t>
    ~DSvector()
    {
        delete[] data;
    }
    //getters
    //template <class t>
    t getData(int pos)
    {
        return data[pos];
    }

    //template <class t>
    int getSize()
    {
        return size;
    }

    //template <class t>
    int getCapacity()
    {
        return capacity;
    }
    // = operator
    //template <class t>
    DSvector& operator=(const DSvector&)
    {

    }
    //[] operator
    //template <class t>
    t& operator[](unsigned int x)
    {
        return data[x];
    }
    //push back
    //template <class t>
    void push_back(t val)
    {
        if(size == capacity)
        {
            resize();
        }
        data[size] = val;
        //std::cout << data[size] << " = data at : " << size << std::endl;
        size++;
    }

    //slides one word to the next spot
    void slide(t s, int pos)
    {
        t temp;
        temp = data[pos];
        size++;
        data[pos+1] = temp;
        data[pos] = s;

    }

    void insert(t arg, int pos)
    {
        DSvector <t> temp;
        for(int i = pos; i < size; i++)
        {
            temp.data[i] = data[i];
        }
        data[pos] = arg;
        for(int i = pos; i < size; i++)
        {
            data[i+1] = temp.data[i];
        }
        size++;
        //delete temp;
    }
    void swapPos(int pos1, int pos2)
    {
        t temp = data[pos1];
        data[pos1] = data[pos2];
        data[pos2] = temp;
    }

    void remove(int pos)
    {
       for(int i = pos; i < size; i++)
       {
          data[pos] = data[pos+1];
       }
       size--;
    }

    bool found(t val)
    {
        for (int i=0; i < size; i++)
        {
            if(data[i]==val)
            {
                return true;
            }
        }
        return false;
    }
};

#endif // DSVECTOR_H
