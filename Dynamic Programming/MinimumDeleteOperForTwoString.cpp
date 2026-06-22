
// Leetcode 583 ( Delete operation for two string ) Medium

// Logic - find lcs and subtract from both string length and add result

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    vector<vector<int> > dp;

    int lcs(string& word1, string& word2, int i, int j){
        if(i >= word1.size()) return 0;
        if(j >= word2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        // take both
        if(word1[i] == word2[j]) {
            return dp[i][j] = 1 + lcs(word1,word2,i+1,j+1);
        } else {
            return dp[i][j] = max(lcs(word1,word2,i+1,j) , lcs(word1,word2,i,j+1));
        }
        return dp[i][j];
    }

    int minDistance(string word1, string word2) {
        dp.clear();
        dp.resize(600,vector<int>(600,-1));
        int len1 = word1.length();
        int len2 = word2.length();
        int lcsLen = lcs(word1,word2,0,0);
        int ans = (len1-lcsLen) + (len2-lcsLen);
        return ans;
    }
};

int main(){

    return 0;
}