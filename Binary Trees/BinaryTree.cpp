//
//  BinaryTree.cpp
//  ECE309Tester
//
//  Created by Christian Burke on 10/10/18.
//  Copyright © 2018 Christian Burke. All rights reserved.
//

#include <stdio.h>

class BTNode
{
public: int data;
    BTNode* left;
    BTNode* right;
    
    BTNode(int d, BTNode* l = NULL, BTNode* r = NULL)
    {
        data = d;
        left = l;
        right = r;
    }
    
};


int main ()
{
    
    BTNode *root = new BTNode(100);
    root->left = new BTNode(25);
    root->left = new BTNode(150);
    
    
    return 0;
}
