//
//  PList.cpp
//  ECE309Tester
//
//  Created by Christian Burke on 9/26/18.
//  Copyright © 2018 Christian Burke. All rights reserved.
//

#include <stdio.h>
#include "PList.h"

//OBJECTS/////////////////////////
void Object::print(){
    printf("Object");
}


Interger::Interger(int num)
{
    number = num;
}
void Interger::print(){
    printf("%d", number);
}


String::String(const char* s){
    string = s;
}
void String::print(){
    printf("%s", string);
}


Double::Double(double doob){
    dub = doob;
}
void Double::print(){
    printf("%f", dub);
}


//POLYLIST/////////////////////////
PolyList::PolyList(){
    head = NULL;
    tail = NULL;
    iterator = PolyIterator(head);
}

void PolyList::insertAfter(PolyList::PolyIterator it, Object* obj)
{
    PolyNode* newNode = new PolyNode(obj);
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    if(tail == NULL)
    {
        tail = newNode;
    }
    
    newNode->next = it.getNext();
    newNode->prev = it.getPrev();
}



//POLYNODE/////////////////////////
PolyList::PolyNode::PolyNode(){
    next = NULL;
    prev = NULL;
}

PolyList::PolyNode::PolyNode(Object* stuff)
{
    data = *stuff;
    next = NULL;
    prev = NULL;
}


//POLYITERATOR/////////////////////
PolyList::PolyIterator::PolyIterator(PolyList::PolyNode* n){
    node = n;
}

PolyList::PolyNode* PolyList::PolyIterator::getNext(){
    if(node != NULL)
    {
        return node->next;
    }
    else{return NULL;}
}
PolyList::PolyNode* PolyList::PolyIterator::getPrev(){
    if(node != NULL)
    {
        return node->prev;
    }
    else{return NULL;}
}


int PolyList::PolyIterator::incrementForward(){
    PolyNode* nextNode = getNext();
    if (nextNode != NULL)
    {
        node = nextNode;
        return 1;
    }
    else
    {
        printf("list has ended");
        return 0;
    }
}



