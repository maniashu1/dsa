
//Leetcode 62 ( Unique paths ) Medium

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:

    vector<vector<int>> dp;

    int paths(int row, int col, int m, int n){

        if(row >= m || col >= n) return 0; 
        if(row == m-1 && col == n-1) return 1; // we have found 1 path
        if(dp[row][col] != -1) return dp[row][col];
        int downways = paths(row+1,col,m,n);
        int rightways = paths(row,col+1,m,n);
        return dp[row][col] =  rightways + downways;
    }

    int uniquePaths(int m, int n) {
        dp.clear();
        dp.resize(105,vector<int>(105,-1));
        return paths(0,0,m,n);
    }
};

int main(){

    return 0;
}