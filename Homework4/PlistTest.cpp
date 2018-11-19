//
//  test.cpp
//  ECE309Tester
//
//  Created by Christian Burke on 9/26/18.
//  Copyright © 2018 Christian Burke. All rights reserved.
//

#include <stdio.h>
#include "PList.h"

PolyList l = PolyList();

Object *i = new Interger(5);
Object *s = new String("hey");

int main()
{
    l.insertAfter(l.iterator, i);
    l.insertAfter(l.iterator, s);
    i->print();
    s->print();
    l.iterator.getNext();
    
    return 0;
}
