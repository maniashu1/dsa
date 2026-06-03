 // Leetcode 198 ( House Robber ) medium

 #include<iostream>
 #include<vector>
 using namespace std;

 // memoization technique
class Solution {
public:
    int amount(vector<int>& nums,int i,vector<int>& dp){
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int take = nums[i] + amount(nums,i+2,dp);;
        int skip = amount(nums,i+1,dp);
        return dp[i] = max(take,skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return amount(nums,0,dp);
    }
};


// tabulation method 

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp(n,-1);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i=2; i<n; i++){
            int take = nums[i] + dp[i-2];
            int skip = dp[i-1];
            dp[i] = max(take,skip);
        }
        return dp[n-1];
    }
};


 int main(){


    return 0;
 }