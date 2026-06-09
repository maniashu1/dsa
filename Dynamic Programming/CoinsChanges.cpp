// Leetcode 322 ( Coins changes ) medium

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int dp[10010];

    int fun(int amount, vector<int>& coins) {
        if (amount == 0) return 0;
        if(dp[amount] != -1) return dp[amount];
        int ans = INT_MAX;
        for(int coin : coins){
            if(amount - coin >= 0) 
            ans = min(ans+0LL,fun(amount-coin,coins)+1LL); // converting integers into LL Bcoz INT_MAX + 1 gives overflow error
        }
        return dp[amount] = ans;
            
    }

    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int ans = fun(amount,coins);
        return ans == INT_MAX ? -1 : ans;

    }
};

int main(){

    return 0;
}