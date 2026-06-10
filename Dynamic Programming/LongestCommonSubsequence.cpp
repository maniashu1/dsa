

// Leetcode 1143 ( Longest common subsequence ) medium 

#include<iostream>
#include<string>
#include<vector>
using namespace std;

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

int main(){


    return 0;
}