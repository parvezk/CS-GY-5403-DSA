//
//  main.cpp
//  Character Reversal Program
//  This program creates a singly-linked list of nodes,
//  each with character data in order and then reverses the order of node
//
//  Created by Parvez Kose on 10/14/17.
//  Copyright © 2017 Parvez Kose. All rights reserved.
//

#include <iostream>
using namespace std;
typedef char ItemType;

struct NodeType;
typedef NodeType* NodePtr;


struct NodeType
{
    ItemType component;
    NodePtr link;
    NodePtr prev;
};

NodePtr head;       // External pointer to list
NodePtr newNodePtr; // Pointer to newest node
NodePtr currPtr;    // Pointer to last node
NodePtr prevPtr;

int main(int argc, const char * argv[]) {
    
    head = new NodeType;
    head->component = 'A';
    
    newNodePtr = new NodeType;
    newNodePtr->component = head->component;
    (*newNodePtr).component++;
    newNodePtr->link = nullptr;
    newNodePtr->prev = head;
    
    head->link = newNodePtr;
    head->prev = nullptr;
    
    currPtr = head;
    prevPtr = head;
    char initial = newNodePtr->component;
    
    for (char c = initial; c<='Z'; ++c)
    {
        newNodePtr = new NodeType;
        newNodePtr->component = c;
        newNodePtr->prev = currPtr;
        
        currPtr->link = newNodePtr;
        currPtr->prev = prevPtr;
        
        prevPtr = currPtr;
        currPtr = newNodePtr;
    }
    currPtr->link = nullptr;    // Mark end of the list
    
    // Print Alphabetical Order
    currPtr = head;
    for (int count = 0; count<26; count++)
    {
        cout << currPtr->component << " ";
        currPtr = currPtr->link;
    }
    
    cout << endl << endl;
    
    // Reverse Order
    currPtr = newNodePtr; // Last Node created
    currPtr->link = newNodePtr -> prev;
    
    for (int count = 0; count<26; count++)
    {
        currPtr = prevPtr;
        prevPtr->link = prevPtr->prev;
        prevPtr = prevPtr->prev;
        
    }
    prevPtr = NULL;
    
    // Print Reversal Order
    currPtr = newNodePtr;
    for (int count = 0; count<26; count++)
    {
        cout << currPtr->component << " ";
        currPtr = currPtr->link;
    }
    
    cout << endl << endl;
    
    return 0;
}

