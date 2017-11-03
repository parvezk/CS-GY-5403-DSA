//1) Print the following array to the screen using a loop:
#include <bits/stdc++.h>
using namespace std ;

int main (){
    int array[] = { 6, 4, 7, 3, 8, 2, 1, 9, 5 };
    const int arrayLength = sizeof(array) / sizeof(array[0]);
    
    for (int index=0; index<arrayLength; ++index)
        std::cout << array[index] << " ";
        return 0;
    
}
