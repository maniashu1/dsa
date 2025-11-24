#include<iostream>
using namespace std;

int linearSearch(int arr[] , int target , int n){
   for(int i=0; i<n; i++){
    if(arr[i] == target){
        return i;
    }
   }
   return -1;
}

int main(){
  int n;
  cout << "Enter the size of the array :";
  cin >> n;

  int arr[n]; 

  cout << "Enter the element of the array : ";

  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  int target;
  cout << "Enter the element you want to search : ";
  cin >> target;

  int result = linearSearch(arr,target,n);

  if(result > 0){
    cout << "Target is found at the index :" << result ;
  } else {
    cout << "Target is not present in the array..";
  }

    return 0;
}