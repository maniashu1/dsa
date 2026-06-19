
// Leetcode 279 ( Perfect square ) Medium 

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    vector<int> dp;

    bool isPerfectSquare(int n){
        int sqt = sqrt(n);
        if(sqt*sqt == n) return true;
        else return false;
    }

    int helper(int n){
        if(isPerfectSquare(n)) return 1;
        if(dp[n] != -1) return dp[n];
        int ans = INT_MAX;
        for(int i=1; i*i<=n; i++){
           int count = helper(i*i) + helper(n-i*i);
           ans = min(ans,count);
        }
        return dp[n] = ans; 
    }

    int numSquares(int n) {
        dp.clear();
        dp.resize(10005,-1);
        return helper(n);
    }
};

int main(){

    return 0;
}