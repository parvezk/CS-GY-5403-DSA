//
//  main.cpp
//  02. Implement and execute Johnson’s algorithm for 5 objects.
//
//  Created by Parvez Kose on 9/28/17.
//  Copyright © 2017 Parvez Kose. All rights reserved.
//

#include <iostream>
using namespace std;
int p, q;
int n = 4;

void findlargenumber(int num[], int vane[], int &value_largenum, int &place_largenum,bool &finish);
void movelargenumber(int num[], int vane[], int begin, int leave);
void changewind(int num[], int vane[], int &m);
void display(int num[],int vane[],int &counter);  void next(int num[], int vane[],bool &finish);

int main(int argc, const char * argv[]) {
    
    int num[6];
    int vane[6];
    for (int i=1; i<n+1; i++) {
        num[i] = i;
        vane[i] = -1;
    }
    num[0] = n+1;
    num[5] = n+1;
    int counter = 0;
    bool finish = false;
    while (finish == false)
    {
        display(num,vane,counter);
        next(num, vane, finish);
    }
    return 0;
}

void findlargenumber(int num[], int vane[], int &value_largenum, int &place_largenum,bool &finish) {
    value_largenum = 0;
    finish = true;
    
    for(int k=1; k<n+1; k++) {
        if ((num[k]>num[k + vane[k]]) && (num[k] >value_largenum)) {
            value_largenum = num[k];
            place_largenum = k;
            finish = false;
        }
    }
}


void movelargenumber(int num[], int vane[], int begin, int leave)  {
    swap(num[begin], num[leave]);
    swap(vane[begin], vane[leave]);
}

void changewind(int num[], int vane[], int &m) {
    for(int h=1; h<n+1; h++) {
        if(num[h]>m){
            vane[h] = -vane[h];
        }
    }
}

void display(int num[],int vane[],int &counter) {
    
    for(int i=1;i<n+1;i++) {
        if (vane[i] == -1) {
            cout << "->" << " ";
        } else if (vane[i] == 1){
            cout << "<-" << " ";
        }
    }
    cout << endl;
    
    for(int i=1;i<n+1;i++) {
        cout << num[i] << "  ";
    }
    cout << endl;
    cout << endl;
    
    if (counter%n == 0) {
        cout << endl;
    }
}

void next(int num[], int vane[], bool &finish) {
    findlargenumber(num, vane, p, q, finish);
    if(finish == false){
        movelargenumber(num, vane, q, q + vane[q]);
        changewind(num, vane, p);
    }
}

