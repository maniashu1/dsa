#include<iostream>
using namespace std;

// Brute force approach
void leftRotatedArraybyOne(int arr[] , int n){
    int temp = arr[0];
    for(int i=1; i<n; i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
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
    
    leftRotatedArraybyOne(arr,n);

    Display(arr,n);


    return 0;
}