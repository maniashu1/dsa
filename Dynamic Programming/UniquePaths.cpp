
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

// Tabulation method 

class Solution {
public:

    
    int uniquePaths(int m, int n) {
       int dp[m][n];
       for(int i=0; i<m;i++){
        for(int j=0; j<n; j++){
            if(i == 0 || j == 0) {
                 dp[i][j] = 1;
            }
            else {
                 dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
       }
       return dp[m-1][n-1];
    }
};

int main(){

    return 0;
}