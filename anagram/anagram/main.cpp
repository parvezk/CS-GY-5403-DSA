//
//  main.cpp
//  anagram
//
//  Created by Parvez Kose on 10/16/17.
//  Copyright © 2017 Parvez Kose. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;

void ArraySort(char *arr, int si, int ei);
bool TestAnagram(char *str1, char *str2);

int main()
{
    char str1[30];
    char str2[30];
    
    cout<<"Enter first string :";
    cin >> str1;
    cout<<"Enter second string :";
    cin >> str2;
    
    if (TestAnagram(str1, str2))
        cout << "True - Strings Are Anagrams";
    else
        cout << "False, Strings Are Not Anagrams";
    
    cout << endl;
    cout << endl;
    
    return 0;
}

void exchange(char *a, char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(char A[], int si, int ei)
{
    char x = A[ei];
    int i = (si - 1);
    int j;
    
    for (j = si; j <= ei - 1; j++)
    {
        if(A[j] <= x)
        {
            i++;
            exchange(&A[i], &A[j]);
        }
    }
    exchange (&A[i + 1], &A[ei]);
    return (i + 1);
}

void ArraySort(char A[], int si, int ei)
{
    int pi; /* Partitioning index */
    if(si < ei)
    {
        pi = partition(A, si, ei);
        ArraySort(A, si, pi - 1);
        ArraySort(A, pi + 1, ei);
    }
}

bool TestAnagram(char *str1, char *str2)
{
    // Get lenghts of both strings
    int n1 = strlen(str1);
    int n2 = strlen(str2);
    
    // If length of both strings is not same, then they
    // cannot be anagram
    if (n1 != n2)
        return false;
    
    // Sort both strings
    ArraySort(str1, 0, n1 - 1);
    ArraySort(str2, 0, n2 - 1);
    
    // Compare sorted strings
    for (int i = 0; i < n1; i++)
        if (str1[i] != str2[i])
            return false;
    
    return true;
}
