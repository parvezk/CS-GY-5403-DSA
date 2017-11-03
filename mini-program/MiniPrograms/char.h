//
//  char.h
//  Arrays
//
//  Created by Parvez Kose on 10/9/17.
//  Copyright © 2017 Parvez Kose. All rights reserved.
//

#ifndef char_h
#define char_h

#include <iostream>
#include <array>
using namespace std;

int main () {
    
    char letter;
    letter = 'A';
    for (int i = 0; i < 3; i++) {
        letter++;
        cout << letter;
    }
    return 0;
}

#endif /* char_h */
