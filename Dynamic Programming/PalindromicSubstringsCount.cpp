
// Leetcode 647 ( Palindromic Substrings ) Medium 

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    int countSubstrings(string s) {
        int n = s.length();
        dp.clear();
        dp.resize(n,vector<int>(n,0));
        int count = 0;
        for(int k=0; k<n; k++){
            int i = 0; 
            int j = k;
            while(j<n){
                 // one length palindrome 
                 if(i == j) {
                    dp[i][j] = 1;
                    count++;
                 }
                 // two length palinddrome
                 else if( j == i+1){
                    if(s[i] == s[j]){
                        dp[i][j] = 1;
                        count++;
                    }
                 } 
                 // more than 2 length palindrome 
                 else {
                    if(s[i] == s[j]){
                        if(dp[i+1][j-1] == 1){
                            dp[i][j] = 1;
                            count++;
                        }
                    }
                 }
                 i++; j++;
            }
        }
        return count;
    }
};

int main(){

    return 0;
}