//Leetcode 1155 ( Number of dice rolls with target sum ) medium

#include<iostream>
#include<vector>
using namespace std;


#define ll long long int
#define mod 1000000007


class Solution {
public:
    vector<vector<int>> dp;  // n and t both is changing thats why state of dp is 2 i.e, we use 2D dp
     
    int fun(int n, int k, int t){
         if(n==0 && t==0) return 1; // dice is exhaust and target is achieved
         if(n == 0) return 0; // dice is exhausted
         if(dp[n][t] != -1) return dp[n][t];
         int ways = 0;
         for(int i=1; i<=k ; i++){
            if(t-i < 0) continue;
            ways = ((ways%mod) + fun(n-1,k,t-i)%mod)%mod;
         }
         return dp[n][t] = ways%mod;
    }
    int numRollsToTarget(int n, int k, int t) {
        dp.clear();
        dp.resize(35,vector<int>(1005,-1));
        return fun(n,k,t);
    }
};

int main(){

    return 0;
}