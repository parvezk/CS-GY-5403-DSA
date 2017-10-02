//
//  main.cpp
//  program1
//
//  Created by Parvez Kose on 9/28/17.
//  Copyright © 2017 Parvez Kose. All rights reserved.
//

#include <iostream>
using namespace std;
typedef int ItemType;

struct NODE;
typedef NODE *NodePtr;
void delete_position(int pos);

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
    
    NodePtr second;
    second = new NODE;
    second->data = 2;
    
    while (deathcount < n) {

        if(iteration == m){
            cout << "Death Index: " << current->data << endl;
            previous->next=current->next;
            current = current->next;
            
            iteration = 0;
            deathcount++;
            
        } else {
            //cout << "prev:" << previous->data << " curr:" << current->data << endl;
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


// TODO: implement m-counter
// TODO: implement NODE deletion
