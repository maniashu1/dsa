#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int> &arr , int n){
   for(int i=0; i<n-1; i++){
    int min = INT_MAX;
    int minIdx = -1;
    // minimum element calculation 
    for(int j=i; j<n; j++){
        if(arr[j] < min){
            min = arr[j];
            minIdx = j;
        }
    }
    swap(arr[i], arr[minIdx]);
   }
}

int main(){

    int n;
    cout << "Enter the size of the array : ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the element of the array :";

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << "Sorted array : ";

    selectionSort(arr , n);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}