#include<iostream>
using namespace std;

// Brute force approach 

void leftRotatedArraybyk(int arr[] , int k , int n){
   int d = k % n;
   int temp[d];

   for(int i=0; i<d; i++){
    temp[i] = arr[i];
   }

   for(int i=d; i<n; i++){
    arr[i-d] = arr[i];
   }

   int j = 0;
   for(int i=n-d; i<n; i++){
     arr[i] = temp[j];
     j++;
   }

}

void Display(int arr[] , int n){

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}

int main(){

    int n;
    cout << "Enter the size of the array : ";
    cin >> n;

    int arr[n];

    cout << "Enter the element of the array: ";

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    int k;
    cout << "Enter the k'th position for rotation : ";
    cin >> k;

    leftRotatedArraybyk(arr,k,n);

    Display(arr,n);

    return 0;
}