//
//  reversal.h
//  Arrays
//
//  Created by Parvez Kose on 10/9/17.
//  Copyright © 2017 Parvez Kose. All rights reserved.
//

#include <iostream>
using namespace std;

#ifndef reversal_hpp
#define reversal_hpp

void newArray(){
    int value[10];
    int number;
    
    for (number = 0; number < 10; number++) {
        cout << "enter numb ";
        cin >> value[number];
    }
    for (number = 9; number >=0; number--) {
        cout << "de: " << value[number] << '\n';
    }
}



#endif /* reversal_hpp */
