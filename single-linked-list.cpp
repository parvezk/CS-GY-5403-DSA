//
//  main.cpp
//  03. Imagine that N people have decided to commit mass suicide by arranging themselves in a circle and killing the Mth person around the circle, closing the ranks as each person drops out of the circle.
//  Find out which person is the last to die, or, more generally, find the order in which those people are executed.
//  For example, if N = 9 and M = 5, the people are killed in the following order: 5,1,7,4,3,6,9,2,8.
//
//  Write C++ code that implements a solution (dynamic storage allocation, any number of people, using a linked list).
//
//  Created by Parvez Kose on 9/28/17.
//  Copyright © 2017 Parvez Kose. All rights reserved.
//

#include <iostream>
using namespace std;
typedef int ItemType;

struct NODE;
typedef NODE *NodePtr;

struct NODE {
    ItemType data;
    NodePtr next;
};

int main (int argc, const char * argv[]) {
    NodePtr head;            // external ptr to list
    NodePtr newNodePtr;        // ptr to newest node
    NodePtr currPtr;        // ptr to last node
    int n, m;
    
    cout << "Enter number of people: ";
    cin >> n;
    cout << "Enter interval: ";
    cin >> m;
    head = new NODE;
    head->data = 1;
    currPtr = head;
    
    for (int i = 2; i <= n; i++)
    {
        newNodePtr = new NODE;    // create new node
        newNodePtr->data = i;    // set data value
        currPtr->next = newNodePtr;    // link node into list
        currPtr = newNodePtr;    // set currPtr to last node
    }

    currPtr->next = NULL;
    currPtr = head;
    for (int i = 0; i < n; i++)
    {
        //cout << currPtr->data << endl;
        currPtr = currPtr->next;
    }
    
    int deathcount = 0;
    int iteration = 1;
    NODE *current = new NODE;
    NODE *previous = new NODE;
    current = head;

    while (deathcount < n) {
        
        if(iteration == m){
            cout << "Death Number: " << " " << current->data << endl;
            previous->next=current->next;
            current = current->next;
            
            iteration = 0;
            deathcount++;
        } else {
            previous = current;
            current = current->next;
            
            if(previous->data == n){
                if(deathcount > 2){
                    current = head->next;
                } else {
                    current = head;
                }
            }
        }
        iteration++;
    }
    return 0;
}
