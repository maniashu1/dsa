
// Leetcode 1312 ( Minimum insertion steps to make a string palindrome ) Hard

// logic - in string length sub lcsPalindrome length 

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    vector<vector<int>> dp;

    int lcsPalindrome(string&s, string& srev , int i , int j){
        if(i >= s.size()) return 0;
        if(j >= srev.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        // take both
        if(s[i] == srev[j]) {
            return dp[i][j] = 1 + lcsPalindrome(s,srev,i+1,j+1);
        } else {
            // include s[i] and exclude srev[j]
            // include srev[j] and exclude s[i]
            return dp[i][j] = max(lcsPalindrome(s,srev,i+1,j) , lcsPalindrome(s,srev,i,j+1));
        }
        return dp[i][j];
    }

    int longestPalindromeSubseq(string s) {
        int n = s.length();
        dp.clear();
        dp.resize(n,vector<int>(n+5,-1));
        string srev = s;
        reverse(srev.begin(),srev.end());
        return lcsPalindrome(s,srev,0,0);
    }

    int minInsertions(string s) {
        int len = s.length();
        int lcsPalen = longestPalindromeSubseq(s);
        return len - lcsPalen;
    }
};

int main(){

    return 0;
}