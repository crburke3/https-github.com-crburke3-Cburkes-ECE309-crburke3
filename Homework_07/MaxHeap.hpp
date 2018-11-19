//
//  MaxHeap.hpp
//  ECE309Tester
//
//  Created by Christian Burke on 10/30/18.
//  Copyright © 2018 Christian Burke. All rights reserved.
//

#ifndef MaxHeap_hpp
#define MaxHeap_hpp

#include <stdio.h>
#include <cstdlib>

class MaxHeap {
private:
    int *heapArray;    // this is the maxheap
    int heapArraySize; // size of the array
    int nextIndex;     // location of next free array entry
    
protected:
    void percolate_up(int);
    void percolate_down(int, int);
    
public:
    MaxHeap(int size = 100) : heapArraySize(size) {
        heapArray = new int[size];
        for (int i = 0; i < size; i++)
            heapArray[i] = 0;
        nextIndex = 0;
    }
    
    void print() {
        for (int i = 0; i < nextIndex; i++) {
            printf("%d ", heapArray[i]);
        }
        printf("\n");
    }
    
    void topthree(int &gold, int &silver, int &bronze) const;
    bool insert(int);
    bool remove(int &); // remove the max value
};


void MaxHeap::percolate_up(int index) {
    while (index > 0) {
        int parent_index = (index - 1) / 2;
        if (heapArray[index] > heapArray[parent_index]) {
            int tmp = heapArray[index];
            heapArray[index] = heapArray[parent_index];
            heapArray[parent_index] = tmp;
            index = parent_index;
        } else
            return;
    }
}


void MaxHeap::percolate_down(int index, int size) {
    int child_index = index * 2 + 1;
    int val = heapArray[index];
    while (child_index < size) {
        int max_val = val;
        int max_index = -1;
        for (int i = child_index; i < child_index + 2 && i < size; i++) {
            if (heapArray[i] > max_val) {
                max_val = heapArray[i];
                max_index = i;
            }
        }
        if (max_val == val)
            return;
        heapArray[index] = max_val;
        heapArray[max_index] = val;
        index = max_index;
        child_index = index * 2 + 1;
    }
}

bool MaxHeap::insert(int data) {
    if (nextIndex < heapArraySize) {
        heapArray[nextIndex] = data;
        percolate_up(nextIndex);
        nextIndex++;
        return true;
    } else {
        return false;
    }
}

bool MaxHeap::remove(int &val) {
    if (nextIndex > 0) {
        val = heapArray[0];
        heapArray[0] = heapArray[nextIndex - 1];
        nextIndex -= 1;
        percolate_down(0, nextIndex);
        return true;
    }
    return false;
}

void MaxHeap::topthree(int &gold, int &silver, int &bronze) const
{
    
    if(heapArraySize == 1)
    {
        gold = heapArray[0];
    }
    if(heapArraySize == 2)
    {
        gold = heapArray[0];
        silver = heapArray[1];
    }
    if(heapArraySize >= 3)
    {
        gold = heapArray[0];
        silver = heapArray[1];
        if(heapArray[2] > silver)
        {
            silver = heapArray[2];
        }
        int max = silver;
        for(int i=3; i<=7; i++)
        {
            if(heapArray[i] > max)
            {
                max = heapArray[i];
            }
        }
        bronze = max;
    }
}




#endif /* MaxHeap_hpp */

