//
//  main.cpp
//  recurse-1
//
//  Created by Parvez Kose on 10/30/17.
//  Copyright © 2017 Parvez Kose. All rights reserved.
//

#include <iostream>
using namespace std;

void recPraise (int n, string line) {
    
    if (n==0 || n<0){
        return;
    }

    for (int i = 1; i<=n; i++){
        cout << i << " " << line << endl;
    }
   
}

int main(int argc, const char * argv[]) {
    // insert code here...
    recPraise(6, "data structure is great");
    return 0;
}
