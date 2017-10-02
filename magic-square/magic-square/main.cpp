#include <iostream>
#include "magic.h"
using namespace std;

int main()
{
    //  First we define some variables
    Magic magicSquare;
    bool finished = false;
    int choice = 0;
    int x, y;
    
    
    //  We have the user input a size of the square that is greater than 0
    while(choice<=0){
        cout<<"Input square size(greater than zero): ";
        cin>>choice;
    }
    
    
    //  Now let's set the size of the magicSquare
    //  This will also initialize the number pointer within the class
    //  and also set a default value for all the numbers
    //  within the grid.
    magicSquare.setSize(choice);
    
    //  Here we make a game loop
    while(!finished){
        //  Here the square should be printed
        //  Example:
        for(int Y=0; Y<magicSquare.getSize(); Y++){
            for(int X=0; X<magicSquare.getSize(); X++){
                if(magicSquare.getNumber(X,Y)==-1)
                    cout<<"*";
                else
                    cout<<magicSquare.getNumber(X,Y);
            }
            cout<<endl;
        }
        //  Menu with choices
        //  where to place the numbers,
        //  what numbers to place,
        //  quit etc...
        //  I'll just toss in an example of how to enter numbers:
        cout<<"Enter x, y, and number: ";
        cin>>x>>y>>choice;
        
        magicSquare.setNumber(x,y,choice);
        
        //  Here should be added something for checking
        //  if the user has won and maybe a bunch of other stuff.
        //  But this is up to you.
        
        //  At some point when you have a winner do this:
        finished = true;
    }
    //  If you're not running the program from the console
    //  you might want to pause here so the program
    //  don't automatically close.
    return 0;
}
