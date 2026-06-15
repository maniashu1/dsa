
//Leetcode 2742 ( Painting the walls ) Hard

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int dp[505][505];
    
    int fun(vector<int>&cost, vector<int>& time, int idx, int remaining){
        if(remaining <= 0) return 0;
        int n = cost.size();
        if(idx == n ) return 1e9;

        if(dp[idx][remaining] != -1) return dp[idx][remaining];

        int paint = cost[idx]+fun(cost,time,idx+1,remaining-1-time[idx]);  // paint the it walll
        int dontPaint = fun(cost,time,idx+1,remaining);    // dont paint the ith wall 

        dp[idx][remaining] = min(paint,dontPaint);

        return dp[idx][remaining];
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        memset(dp,-1,sizeof dp);
        int n = cost.size();
        return fun(cost,time,0,n);
    }
};

int main(){

    return 0;
}