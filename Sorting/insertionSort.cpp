#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int> &arr , int n){
     for(int i=1 ; i<n; i++){
        int j = i;
        while(j>=1 && arr[j] < arr[j-1]){
           swap(arr[j] , arr[j-1]) ;
           j-- ;
        }
     }

}

int main(){
    int n;
    cout << "Enter the size of the array :";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the element of the array : ";

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    insertionSort(arr , n);

    cout << "Sorted array : ";
    
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}