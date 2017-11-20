#include <bits/stdc++.h>
using namespace std ;

int createTwoNumbers(int num){
	int numAsc,numDesc ;
	std::vector<int> digits;
	digits.clear() ;
	while( num > 0){
		cout << num%10 << " " ;

		digits.push_back(num%10);
		num/=10 ;
	}
	cout << endl ;
	// if(digits.size() > 4 ){
	// 	cout << "Enter a 4  digit number next time" ;
	// 	exit (1) ;
	// }

	sort(digits.begin(), digits.end());

	if(digits[0] == digits[3]){
		cout << "All 4 digits same" ;
		exit (1) ;
	}
	numAsc = 0 ;
	int len = digits.size() ;
	for(int i = 0 ; i < len ; i++){
		numAsc = numAsc*10 + digits[i] ;
	}
	cout << "Ascending : " << numAsc << endl ;
	numDesc = 0 ;
	for(int i = len -1 ; i >= 0 ; i--){
		numDesc = numDesc*10 + digits[i] ;
	}
	cout << "Descending  :" << numDesc << endl ;

	return numDesc - numAsc ;


}
int main (){

	int num ;
	int numPrev;
    cout << "Enter a 4 digit number : " << endl;
	cin >> num ;
	numPrev = 0; int newNoCreated = num;
	do {
	 numPrev = newNoCreated ;
	 newNoCreated = createTwoNumbers(numPrev) ;
	 cout << "Num prev" << numPrev << endl ;
	 cout << "Num created" << newNoCreated << endl ;
	 // if(numPrev == newNoCreated) {cout << "Wooho" << endl ;break ;}

	}while(numPrev != newNoCreated) ;

	cout << "Final Answer : " << numPrev << endl ;
}
