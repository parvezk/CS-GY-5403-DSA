// Program P4

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct node {
    int data;
    string name;
    struct node *next;
} Node, *NodePtr;


int main() {
    
    NodePtr makeNode(int);
    int lengthOfPegs(NodePtr);
    NodePtr AddNode(NodePtr, NodePtr);
    NodePtr DeleteNode(NodePtr);
    NodePtr swap(NodePtr, NodePtr);
    NodePtr np;
    
    // LLA
    NodePtr A = new Node;
    A -> data = 0;
    A -> next = nullptr;
    
    // LLB
    NodePtr B = new Node;
    B -> data = 0;
    B -> next = nullptr;
    
    // LLC
    NodePtr C = new Node;
    C -> data = 0;
    C -> next = nullptr;
    
    int N = 3;
    
    A -> name = "A";
    B -> name = "B";
    C -> name = "C";
    
    for (int i=1; i<=N; i++) {
        np = makeNode(i);
        np -> next = A;
        A = np;
    }
    
    while (lengthOfPegs(B) < N) {
        
        if (N % 2 == 0){
            swap(A, B);
            swap(A, C);
            swap(B, C);
        } else {
            swap(A, C);
            swap(A, B);
            swap(B, C);
        }
        
    }
}


int lengthOfPegs(NodePtr peg) {
    int counter = 0;
    while ( peg -> next != NULL){
        counter ++;
        peg = peg -> next;
    }
    return counter;
}

NodePtr makeNode(int n) {
    NodePtr np = new Node;
    np -> data = n;
    np -> next = nullptr;
    return np;
}

NodePtr AddNode(NodePtr From, NodePtr To) {
    
    int disc;
    NodePtr newNode = new Node;
    newNode -> data = (From -> data) > (To -> data) ? From -> data + 1 : To -> data + 1;
    disc = newNode -> data;
    
    newNode -> next = To;
    cout << "Move disc: " << disc <<
    " From ** " << From -> name <<
    " ** To ** " << To -> name << endl;
    newNode -> name = To -> name;
    return newNode;
}

NodePtr DeleteNode(NodePtr peg) {
    string name = (*peg).name;
    if (peg -> next != nullptr) {
        peg = peg -> next;
    }
    peg -> name = name;
    return peg;
}

NodePtr swap(NodePtr X, NodePtr Y) {
    if (X->data > Y->data) {
        AddNode(Y,X);
        DeleteNode(Y);
    } else {
        AddNode(X,Y);
        DeleteNode(X);
    }
    return 0;
}

