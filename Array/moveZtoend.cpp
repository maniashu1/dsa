#include<iostream>
#include<vector>
using namespace std;

void moveZerotoend(int arr[] , int n){
   for(int i=0; i<n; i++){
    if(arr[i] == 0 && arr[i+1] > 0){
        swap(arr[i] , arr[i+1]);
    }
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
    cout << "Enter the element of the array : ";

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    moveZerotoend(arr,n);
    Display(arr,n);

    return 0;
}