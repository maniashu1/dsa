#include<iostream>
#include<vector>
using namespace std;

void BubbleSort(vector<int> &arr , int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
                if(arr[j] > arr[j+1]){
                    int temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
                    
                }
        }
    }
}

int main(){
   cout << "Enter the size of the array : ";
   int n;
   cin >> n;

   vector<int> arr(n);
   cout << "Enter the element of the array : ";
   for(int i=0; i<n; i++){
    cin >> arr[i];
   }

   BubbleSort(arr , n);

   cout << "Sorted Array : ";
   for(int i=0; i<n; i++){
    cout << arr[i] << " ";
   }
    return 0;
}

 