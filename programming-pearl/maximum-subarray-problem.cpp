#include <iostream>
using namespace std;

int maxSubArray(int a[], int size){
  int max_so_far = 0, max_ending_here = 0;
 
  for (int i=0; i<size; i++){
    max_ending_here = max_ending_here + a[i];
    if (max_ending_here < 0)
        max_ending_here = 0;
    if (max_so_far < max_ending_here){
      max_so_far = max_ending_here;
      cout << "" << a[i] << endl;
    }
  }
  return max_so_far;
}

int maxSumNegative(int a[], int size){
  int max_so_far = a[0];
  int curr_max = a[0];
  
  for (int i=1; i<size; i++){
    curr_max = max(a[i], curr_max+a[i]);
    max_so_far = max(max_so_far, curr_max);
  }
  return max_so_far;
}

int main() {
  int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
  //cout << maxSubArray(a, sizeof(a)/4) << endl;
  int b[] = {-2, -4, -4, -7, -3, -2};
  cout << maxSumNegative(b, sizeof(b)/4) << endl;
  return 0;
}

