//
//  Main.cpp
//  ECE309Tester
//
//  Created by Christian Burke on 10/17/18.
//  Copyright © 2018 Christian Burke. All rights reserved.
//

#include <stdio.h>

#include "IntegerSet.h"
#include <cstdlib>
#include <ctime>

int main()
{
    
    class MaxHeap {
    public:
        MaxHeap(int *a, int size, int length = 0)
        : heapArray(a), heapArraySize(size), nextIndex(length) {
            int m = length / 2 - 1;
            while (m >= 0) {
                heap.percolate_down(m, length);
                m--;
            }
        }
        static void sort(int *array, int size); // global function
    };

    void MaxHeap::sort(int *array, int size) {
        MaxHeap maxheap(array, size, size); // construct helper object
        // after construction, array is heapified
        
        for (m = size - 1; m > 0; m--) {
            int ref;
            maxheap.remove(ref); // remove maximum
            array[m] = ref;   // copy to end of array;
        }
        // array is sorted, caller still has access to array
        // maxheap object is destroyed
    }

    
    
    /*
    IntegerSetHT set;
    set.insert(5);
    set.insert(99);
    set.insert(0);
    
    IntegerSetHT::iterator sit = set.begin();
    while(!sit.end())
    {
        printf("%d \n", sit.getInt());
        sit.increment();
    }
*/
    
    
    
    IntegerSetHT set(1000);
    srand(time(NULL));

    for (int i = 0; i<500; i++)
    {
        int r = rand()%1000+1;
        set.insert(r);
    }
    printf("collisions: %d\n\n",set.collisions);
    printf("failures: %d\n",set.failures);

}

