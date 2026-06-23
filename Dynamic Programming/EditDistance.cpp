
// Leetcode 72 ( Edit Distance ) Medium

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    int minSteps(int i , int j, string& s1, string& s2 ){
        if(i == -1) return j+1;
        if( j== -1) return i+1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) {
            return dp[i][j] = minSteps(i-1,j-1,s1,s2);
        } else {
            int del = minSteps(i-1,j,s1,s2);
            int ins = minSteps(i,j-1,s1,s2);
            int rep = minSteps(i-1,j-1,s1,s2);
            return dp[i][j] = 1 + min({del,ins,rep});
        }
    }
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        dp.clear();
        dp.resize(m+1,vector<int>(n+1,-1));
        return minSteps(m-1,n-1,word1,word2);
    }
};


int main(){


    return 0;
}