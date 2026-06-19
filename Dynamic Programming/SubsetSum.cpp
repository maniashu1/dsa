// Subset sum problem

#include<iostream>
#include<vector>
using namespace std;

// now we can do memoization on recursion
// here state of dp is 2 i.e, idx and target both is changing

vector<vector<int>> dp;

bool subsetSum(vector<int>& arr , int target, int idx){

     if(idx == arr.size()){
        if(target == 0) return true;
        return false;
     }
    
     if(dp[idx][target] != -1) return dp[idx][target];
     
     // we have two choices either pick the element and dont pick the element 
     bool dontPick = subsetSum(arr,target,idx+1);
     bool pick = subsetSum(arr,target-arr[idx],idx+1);

     return dp[idx][target] =  dontPick || pick ;

}


int main(){

    dp.clear();
    dp.resize(10,vector<int>(1005,-1));

    int n;
    cout << "Enter the size of the array : ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the element of the array :";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target value : ";
    cin >> target;
    
    cout << subsetSum(arr,target,0);



    return 0;
}