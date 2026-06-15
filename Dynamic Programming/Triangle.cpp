
//Leetcode 120 ( Triangle ) Medium


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    vector<vector<int>> dp;

    int fun(vector<vector<int>>& triangle, int rows, int col){
        if(rows == triangle.size()-1) return triangle[rows][col];
        if(dp[rows][col] != INT_MAX) return dp[rows][col]; 
        
        // we can choose ith col of next rows
        // we can choose i+1th col of next rows
        return dp[rows][col] = triangle[rows][col] + min(fun(triangle,rows+1,col) , fun(triangle,rows+1,col+1));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        dp.clear();
        // cant initialize with -1 bcoz triangle can contain  value -10^4 <= triangle[i][j] <= 10^4
        dp.resize(205,vector<int>(205,INT_MAX)); 

        return fun(triangle,0,0); 
    }
};


int main(){


    return 0;
}