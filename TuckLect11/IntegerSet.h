//
//  IntergerSet.hpp
//  ECE309Tester
//
//  Created by Christian Burke on 10/17/18.
//  Copyright © 2018 Christian Burke. All rights reserved.
//

#ifndef INTEGERSET_H
#define INTEGERSET_H

//#include "List.h"

// IntegerSet abstract base class to demonstrate hash table concepts
class IntegerSet {
protected:
    int size = 100;
    int hash(int key) const { return (key * 987) % size; }
public:
    int count = 0;
    int failures = 0;
    int collisions = 0;
    IntegerSet(int htsize):size(htsize) {}
    IntegerSet():size()
    {
        size = 100;
    }
    virtual bool insert(int) = 0;
    virtual bool search(int) const = 0;
    virtual void remove(int) = 0;
};

// Hash Table with Linear Probing
class IntegerSetHT : public IntegerSet {
protected:
    int siz = 100;
    int *table;
    static int *tab;
    int probeDistance;
    const int empty_since_start = -2;
    const int empty_after_removal = -1;
public:
    IntegerSetHT(int htsize);
    IntegerSetHT();
    virtual bool insert(int) override;
    virtual bool search(int) const override;
    virtual void remove(int) override;
    
    class iterator{
    protected:
        int i = 0;
        int* head;
        int* currentNode;
    public:
        int len = 100;
        int* getHead();
        iterator(int* x);
        void increment();
        int getInt();
        bool end();
    };
public:
    iterator begin();

};


#endif //INTEGERSET_H

