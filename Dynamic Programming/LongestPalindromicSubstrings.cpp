
// Leetcode 5 ( Longest palindtromic Substring ) Medium

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;

    string longestPalindrome(string s) {

        int n = s.length();
        dp.clear();
        dp.resize(n, vector<int>(n, 0));

        // fill the dp matrix
        for (int k = 0; k < n; k++) {
            int i = 0;
            int j = k;
            while (j < n) {
                if (i == j) {
                    dp[i][j] = 1;
                } else if (j == i + 1) {
                    if (s[i] == s[j]) {
                        dp[i][j] = 1;
                    }
                } else {
                    if(s[i] == s[j]){
                        if(dp[i+1][j-1] == 1){
                            dp[i][j] = 1;
                        }
                    }
                }
                i++; j++;
            }
        }
        // finding longest palindromic Substring
        int si = 0;
        int maxLen = 1;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {

                if (dp[i][j] == 1) {

                    int len = j - i + 1;

                    if (len > maxLen) {
                        maxLen = len;
                        si = i;
                    }
                }
            }
        }

        return s.substr(si, maxLen);
    
    }
};


int main(){


    return 0;
}