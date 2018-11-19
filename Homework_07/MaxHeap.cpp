//
//  MaxHeap.cpp
//  ECE309Tester
//
//  Created by Christian Burke on 10/30/18.
//  Copyright © 2018 Christian Burke. All rights reserved.
//

#include "MaxHeap.hpp"

int main() {
    MaxHeap heap;
    
    heap.insert(45);
    heap.print();
    
    heap.insert(100);
    heap.print();
    
    heap.insert(5);
    heap.insert(50);
    heap.print();
    
    int ref;
    heap.remove(ref);
    heap.print();
    
    for (int i = 0; i < 100; i++)
        heap.insert(rand() % 1000);
    
    for (int i = 0; i < 20; i++)
        heap.remove(ref);
    
    heap.print();
    
    return 0;
}

