//
//  IntergerSet.cpp
//  ECE309Tester
//
//  Created by Christian Burke on 10/17/18.
//  Copyright © 2018 Christian Burke. All rights reserved.
//

#include "IntegerSet.h"
#include <stdio.h>
#include <stdlib.h>

// can only hold positive integers
IntegerSetHT::IntegerSetHT(int htsize)
:IntegerSet(htsize)
{
    probeDistance = 20;
    table = new int[size];
    for(int i=0; i<size; i++)
        table[i] = empty_since_start;  // -1 means empty
}

bool IntegerSetHT::insert(int data)
{
    int index = hash(data);
    int bucketsProbed = 0;
    bool collided = false;
    while( bucketsProbed++ < probeDistance )
    {
        
        if ( table[index] < 0 )
        {
            if(collided == true)
            {
                collisions++;
            }
            
            table[ index ] = data;
            return true;
        }
        index = (index+1) % size;
        collided = true;
        
    }
    failures++;
    collisions++;
    // otherwise give up
    return false;
}

bool IntegerSetHT::search(int data) const
{
    int index = hash(data);
    int bucketsProbed = 0;
    while( table[index] != empty_since_start &&
          bucketsProbed++ < probeDistance )
    {
        if ( table[index] == data )
        {
            return true;
        }
        index = (index+1) % size;
    }
    
    // data can only be in one location, check it
    return false;
}

void IntegerSetHT::remove(int data)
{
    int index = hash(data);
    int bucketsProbed = 0;
    while( table[index] != empty_since_start &&
          bucketsProbed++ < probeDistance )
    {
        if ( table[index] == data )
        {
            table[index] = empty_after_removal;
            //return;
        }
        index = (index+1) % size;
    }
}







// can only hold positive integers
IntegerSetHT::IntegerSetHT()
:IntegerSet()
{
    probeDistance = 20;
    table = new int[size];
    for(int i=0; i<size; i++)
        table[i] = empty_since_start;  // -1 means empty
}

IntegerSetHT::iterator::iterator(int* array)
{
    head = array;
}

int IntegerSetHT::iterator::getInt()
{
    
    while(*head < 0)
    {
        increment();
    }
    return *head;
}

void IntegerSetHT::iterator::increment()
{
    head++;
    currentNode++;
    i++;

}


bool IntegerSetHT::iterator::end()
{
    if(i >= len-80)
    {
        return true;
    }
    else
    {
        return false;
    }
}

IntegerSetHT::iterator IntegerSetHT::begin()
{
    int* point;
    point = table;
    iterator newIt(point);
    
    return newIt;
}

int* IntegerSetHT::iterator::getHead()
{
    return head;
}



