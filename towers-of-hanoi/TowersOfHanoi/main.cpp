//
//  main.cpp
//  C++ program for Towers of Hanoi
// Application for Recursive function
//
//  Created by Parvez Kose on 10/23/17.
//  Copyright © 2017 Parvez Kose. All rights reserved.
//

#include <iostream>
using namespace std;
void hanoi(int, char, char, char);

int main(int argc, const char * argv[])
{
    int n; // define to store the number of discs
    cout << "Enter the number of discs: ";
    cin >> n;
    cout << "The sequence of moves involved in the Tower of Hanoi are:\n";
    
    hanoi(n, 'A', 'C', 'B');
    cout << endl;
    return 0;
}

void hanoi(int n, char fr, char tr, char ar)
{
    int count = 0;
    count++;
    if(n == 1)
    {
        printf("\n Move disk 1 from rod %c to rod %c", fr, tr);
        
        return;
    }
    hanoi(n-1, fr, ar, tr);
    printf("\n Move disk %d from rod %c to rod %c", n, fr, tr);
    hanoi(n-1, ar, tr, fr);
    
}
