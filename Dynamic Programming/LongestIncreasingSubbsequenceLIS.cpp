
// Leetcode 300 ( Longest increasing subsequence ) Medium 

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    vector<int> arr;
    vector<int> dp;

    // fun gives the length of lis of ith element 
    int fun(int i){

        if(i==0) return 1;   // base case 
        if(dp[i] != -1) return dp[i];

        int mx = INT_MIN;

        for(int j=0; j<=i-1; j++){
            if(arr[j] < arr[i]){
                mx = max(mx,fun(j));
            }
        }
        
        // corner case if not any smaller element present 
        // i.e, all the element is same and array is in decreasing order
        if(mx == INT_MIN) return dp[i] = 1;

        return dp[i] = 1 + mx;
    }

    int lengthOfLIS(vector<int>& nums) {
        arr = nums;
        dp.clear();
        dp.resize(2505,-1);
        dp[0] = 1;
        int ans = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            ans = max(ans,fun(i));
        } 
        return ans;
    }
};

int main(){

    return 0;
}