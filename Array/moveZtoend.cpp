#include<iostream>
#include<vector>
using namespace std;

void moveZerotoend(int arr[] , int n){
   int i = 0;
   int j = 1;
   while(j < n){
    if(arr[i] == 0 && arr[j] != 0){
        swap(arr[i] , arr[j]);
    } else if(arr[i] != 0){
        i++;
        j++;
    } else if(arr[i] == 0 && arr[j] == 0){
        j++;
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