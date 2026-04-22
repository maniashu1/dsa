#include<iostream>
#include<stack>
using namespace std;
    
int main(){

    int arr[] = {3,1,2,7,4,6,2,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    for(int i=0; i<n; i++){
        cout << arr[i] << "  ";
    }
    cout << endl;
    stack<int> st;
    

    // steps : pop , ans , push and reverse traversal in the array 


    int pge[n];
    // last element of the array has no next greater element 
    pge[0] = -1;
    for(int i=1; i<n; i++){
      // pop all the element smaller than arr[i]
      while(st.size() > 0 && st.top() <= arr[i]){
        st.pop();
      }
      // mark the answer in nge array
      if(st.size() == 0) pge[i] = -1;
      else pge[i] = st.top();
      st.push(arr[i]);
    }
    for(int i=0; i<n; i++){
        cout << pge[i] << " ";
    }

    return 0;
}