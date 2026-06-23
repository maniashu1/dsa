

// Leetcode 1143 ( Longest common subsequence ) medium 

#include<iostream>
#include<string>
#include<vector>
using namespace std;

// recursion and dp memoization method 

class Solution {
public:
    vector<vector<int>> dp;  // 2D dp vector bcoz here state of dp is 2 i.e, i and j both are changing

    int fun(string &s1, string &s2, int i, int j){

        if(i >= s1.size()) return 0;
        if(j >= s2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]){
            // include both
            return dp[i][j] = 1 + fun(s1,s2,i+1,j+1); 
        } else {
            // include s1[i] and not include s2[j]
            // include s2[j] and not include s1[i]
            return dp[i][j] = max(fun(s1,s2,i+1,j),fun(s1,s2,i,j+1));
        }    
    }
    int longestCommonSubsequence(string text1, string text2) {
        dp.clear();
        dp.resize(1000,vector<int>(1005,-1));
        return fun(text1,text2,0,0);
    }
};

// Tabultion method 

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp;
        dp.assign(m+1,vector<int>(n+1,0));
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(text1[i-1] == text2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i][j-1] , dp[i-1][j]);
                }
            }
        } 
        return dp[m][n];

    }

    // Printing length of longest substring 

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp;
        dp.assign(m+1,vector<int>(n+1,0));
        int ans = INT_MIN;
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(text1[i-1] == text2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = 0;
                    ans = max(ans,dp[i][j]);
                }
            }
        } 
        return max;

    }

int main(){


    return 0;
}