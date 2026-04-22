#include<iostream>
#include<stack>
using namespace std;
    
int main(){

    int arr[] = {3,1,2,7,4,6,2,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    stack<int> st;
    

    // steps : pop , ans , push and reverse traversal in the array 


    int nge[n];
    // last element of the array has no next greater element 
    nge[n-1] = -1;
    for(int i=n-2; i>=0; i--){
      // pop all the element smaller than arr[i]
      while(st.size() > 0 && st.top() <= arr[i]){
        st.pop();
      }
      // mark the answer in nge array
      if(st.size() == 0) nge[i] = -1;
      else nge[i] = st.top();
      st.push(arr[i]);
    }
    for(int i=0; i<n; i++){
        cout << nge[i] << " ";
    }

    return 0;
}