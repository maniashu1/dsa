/*
*********
 *******
  *****
   ***
    *
*/

#include<iostream>
using namespace std;

int main(){
   cout << "Enter a number : ";
   int n ;
   cin >> n ;
   for(int i=0; i<n; i++){
    // star
    for(int j=0; j<2*i-1; j++){
        cout<< " ";
    }
    // space
    for(int j=0 ;j<n-i-1; j++){
        cout << "*";
    }
    // star
    for(int j=0 ; j<2*i-1; j++){
        cout << " ";
    }
    cout << endl ;
   }
   
    return 0;
}