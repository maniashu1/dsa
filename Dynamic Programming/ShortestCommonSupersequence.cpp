
// Leetcode 1092 ( Shortest common Supersequence ) Hard

// Logic :- find lcs -> then fill the left and right of the lcs 

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    
    // finding length of lcs 
    string longestCommonSubsequence(string& a, string& b){
        int m = a.length();
        int n = b.length();
        vector<vector<int>> dp;
        dp.assign(m+1,vector<int>(n+1,0));
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(a[i-1] == b[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i][j-1] , dp[i-1][j]);
                }
            }
        } 

        // finding lcs string 

        string lcs = "";
        int i = m;
        int j = n;
        while(i>0 && j>0){
            if(a[i-1] == b[j-1]){
                lcs += a[i-1];
                i--;
                j--;
            } else if(dp[i-1][j] > dp[i][j-1]) i--;
             else j--;
        }
        reverse(lcs.begin(),lcs.end());
        return lcs;
    }

    // finding shortest common supersequence 

    string shortestCommonSupersequence(string str1, string str2) {
        string LCS = longestCommonSubsequence(str1,str2);
        int i=0; int j=0; int k=0;
        string scs = "";
        while(k<LCS.size()){
           while(str1[i] != LCS[k]){
             scs += str1[i];
             i++;
           }
           while(str2[j] != LCS[k]){
            scs += str2[j];
            j++;
           }
           scs += LCS[k];
           i++; j++; k++;
        }
        while(i<str1.size()){
            scs += str1[i];
            i++;
        }
        while(j<str2.size()){
            scs += str2[j];
            j++;
        }
        return scs;
    }
};

int main(){

    return 0;
}