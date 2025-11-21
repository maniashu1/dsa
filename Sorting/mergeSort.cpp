#include<iostream>
#include<vector>
using namespace std;

// merge the two sorted array 
void merge(vector<int> &a , vector<int> &b , vector<int> &res){
  int i = 0;
  int j = 0;
  int k = 0;
  while(i < a.size() && j < b.size()){
     if(a[i] < b[j]){
        res[k++] = a[i++];
     } else {
        res[k++] = b[j++];
     }
  }
  // if a is at end
  if(i == a.size()){
    while(j < b.size()){
        res[k++] = b[j++];
    }
  }
  // if b is at end
  if(j == b.size()){
    while(i < a.size()){
        res[k++] = a[i++];
    }
  }
}

// merge sort
void mergeSort(vector<int> &v){
  int n = v.size();
  if(n == 1) return ;
  int n1 = n/2;
  int n2 = n - (n/2) ;
  vector<int> a(n1);
  vector<int> b(n2);
  // simply copy pasting the element of array in two array
  for(int i=0; i<n1; i++){
    a[i] = v[i]; 
  }
  for(int i=0; i<n2; i++){
    b[i] = v[n1 +i];
  }
  // recursion
  mergeSort(a);
  mergeSort(b);

  merge(a , b, v);
}

int main(){

    int n ;
    cout << "Enter the size of the array : ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the element of the array : ";

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    mergeSort(arr);
    
    cout << "Sorted array :" ;

    for (int i=0;i <n; i++){
        cout << arr[i] << " " ;
    }


    return 0;
}