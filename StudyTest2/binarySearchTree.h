//
//  binarySearchTree.h
//  ECE309Tester
//
//  Created by Christian Burke on 11/11/18.
//  Copyright © 2018 Christian Burke. All rights reserved.
//

#ifndef binarySearchTree_h
#define binarySearchTree_h


#include <stdlib.h>

class BinarySearchTree {
protected:
    class BTNode {
    public:
        int data;
        BTNode *left;
        BTNode *right;
        BTNode *parent;
        int height;
        
        BTNode(int d, BTNode *l = NULL, BTNode *r = NULL, BTNode *p = NULL)
        : data(d), left(l), right(r), parent(p), height(0) {}
    };
    
    virtual bool Case1(BTNode *parent, BTNode *node);
    virtual bool Case2(BTNode *parent, BTNode *node);
    virtual void Case3(BTNode *parent, BTNode *node);
    
    void inorderPrint(BTNode *node);
    
    BTNode *root;
    
    void updateHeight(BTNode *node);
    int computeHeight(BTNode *node);
    
public:
    int count;
    BinarySearchTree() : root(NULL), count(0) {}
    virtual void insert(int data);
    virtual bool search(int data);
    virtual void remove(int data);
    
    virtual void print();
};



#endif /* binarySearchTree_h */
