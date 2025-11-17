#include<iostream>
#include<vector>
using namespace std;

void BinarySearch(vector<int> arr , int target){
   int n = arr.size();
   int lo = 0;
   int hi = n - 1 ;
   while(lo <= hi){
    int mid = lo + (hi - lo) / 2 ;
    if(arr[mid] == target){
       cout << target << " -> is present.";
       return;
    }else if(arr[mid] > target){
        hi = mid - 1 ;
    } else {
        lo = mid + 1;
    }
   }
   cout << target <<" -> is not present." ;
}

int main(){
  cout << "Enter the size of the array : " ;
  int n;
  cin >> n ;
  vector<int> arr(n);
  cout << "Enter the element of the array : ";
  
  for(int i = 0 ; i < n ; i++){
    cin >> arr[i];
  }
  cout << "Enter the element you want to search : ";
  int target;
  cin >> target;
  BinarySearch(arr , target);
 
    return 0;
}