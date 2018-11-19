//
//  Homework6.cpp
//  ECE309Tester
//
//  Created by Christian Burke on 10/17/18.
//  Copyright © 2018 Christian Burke. All rights reserved.
//

#include "Homework6.hpp"

IntegerSetHTChain(int htsize=1000)
:IntegerSet(htsize)
{
    table = new List[size];  // array of lists, default constructed
}

bool IntegerSetHTChain::insert(int data)
{
    List::iterator it;
    table[hash(data)].insertAfter(it,data);
    return true;
}
