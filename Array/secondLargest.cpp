#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the size of the array : ";
    cin >>n;
    
    cout << "Enter the element of the array : ";
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int largestEle = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i] > largestEle){
            largestEle = arr[i];
        }
    }

    int SecondLargestEle = arr[0];

    for(int i=1; i<n; i++){
        if(arr[i] > SecondLargestEle && arr[i] < largestEle){
            SecondLargestEle = arr[i];
        }
    }

    cout << "Second Larget element is : " << SecondLargestEle ;
    return 0;
}