//
//  Homework_05.h
//  ECE309Tester
//
//  Created by Christian Burke on 10/11/18.
//  Copyright © 2018 Christian Burke. All rights reserved.
//

#ifndef Homework_05_h
#define Homework_05_h

#include <stdio.h>
#include "IntegerSetArray.h"
#include <string.h>

class IntegerSet {
protected:
    int size;
    int hash(int key) { return (key * 997) % size; }
    
public:
    IntegerSet(int htsize):size(htsize) {}
    virtual bool insert(int) = 0;
    virtual bool search(int) const = 0;
    virtual void remove(int) = 0;
};

class IntegerSetArray:public IntegerSet{
public:
    int len;
    int* arrayHead;
    IntegerSetArray(int length);
    bool insert(int x);
    bool search(int x) const;
    void remove(int x);
};





//------------INTEGER_SET_ARRAY CLASS-------------------------//
IntegerSetArray::IntegerSetArray(int length):IntegerSet(length)
{
    len = length;
    arrayHead = new int[length];
    for(int i = 0; i<len; i++)
    {
        arrayHead[i] = -1;
    }
}


bool IntegerSetArray::insert(int x)
{
    if(x < 0){return false;}
    
    for(int i = 0; i<len; i++)
    {
        if(arrayHead[i] == -1)  //Find first empty position of array
        {
            arrayHead[i] = x;
            return true;        //Return once number is added
        }
    }
    return false;               //Return false if array is filled
}

bool IntegerSetArray::search(int x) const
{
    for(int i = 0; i<len; i++)
    {
        if(arrayHead[i] == x)
        {
            return true;
        }
    }
    return false;
}

void IntegerSetArray::remove(int x)
{
    for(int i = 0; i<len; i++)
    {
        if(arrayHead[i] == x)
        {
            arrayHead[i] = -1;
        }
    }
}
























#endif /* Homework_05_h */
