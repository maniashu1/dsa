
// Leetcode (746) Min cost to climbing stairs - Easy

#include<iostream>
#include<vector>
using namespace std;

// memoization method 
class Solution {
public:
    int minCost(vector<int>& cost , int idx, vector<int>& dp){
        if(idx == 0 || idx == 1) return cost[idx];
        if(dp[idx] != -1) return dp[idx];
        return dp[idx] = cost[idx] + min(minCost(cost,idx-1,dp) , minCost(cost,idx-2,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        return min(minCost(cost,n-1,dp),minCost(cost,n-2,dp));
    }
};


// Tabulation method 
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i=2; i<n; i++){
            dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-2],dp[n-1]);
    }
};

int main(){

    return 0;
}