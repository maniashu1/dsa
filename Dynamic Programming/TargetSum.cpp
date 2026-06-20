
// Leetcode 494 ( Target sum ) Medium. 

#include<iostream>
#include<vector>
using namespace std;

#define ll long long int
#define offset 1000     // dp index cant be -ve 

class Solution {
public:
    vector<vector<ll>> dp;
    int ways(int idx, vector<int>& nums, int target){
        if(idx == nums.size()){
            if(target == 0) return 1;
            else return 0;
        }
        if(target < -1000 || target > 1000) return 0;  // given constraint 
        
        if(dp[idx][target+offset] != INT_MIN) return dp[idx][target+offset];
        int add = ways(idx+1,nums,target-nums[idx]);
        int sub = ways(idx+1,nums,target+nums[idx]);
        return dp[idx][target+offset] = add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        dp.clear();
        dp.resize(25,vector<ll>(2005,INT_MIN));
        return ways(0,nums,target);
    }
};

int main(){

    return 0;
}