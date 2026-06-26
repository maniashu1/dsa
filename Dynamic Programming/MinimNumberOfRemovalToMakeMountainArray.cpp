
// Leetcode 1671 ( Minimum number of removal to make mountain array ) Hard

// logic :- first fill lis dp from 0 -> n-1 and n-1 -> 0
//  then fill mountain aray len by :- dp3[i] = dp1[i] + dp2[i] - 1;


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    vector<int> dp;
    vector<int> dp1;
    vector<int> dp2;

    // filling longest increaing subsequence dp

    vector<int> fillLIS(vector<int>& nums) {
       int n = nums.size();
       vector<int>dp(n,0);
       int mx = 0;
       for(int i=0; i<n; i++){
        for(int j=0; j<=i-1; j++){
            if(nums[j] < nums[i]){
                dp[i] = max(dp[i],dp[j]);
            }
        }
        dp[i] += 1;
       }
       return dp; 
    }

    int minimumMountainRemovals(vector<int>& nums) {

        int n = nums.size();
        dp.clear();
        dp.resize(n,0);
        dp1.clear();
        dp1.resize(n,0);
        dp2.clear();
        dp2.resize(n,0);

        dp1 = fillLIS(nums);

        reverse(nums.begin(),nums.end());
        dp2 = fillLIS(nums);
        reverse(dp2.begin(),dp2.end());

        // filling dp3 with all possible length of mountain subarray 

        vector<int>dp3(n,0);

        for(int i=0; i<dp1.size(); i++){
            if(dp1[i] > 1 && dp2[i] > 1){
                dp3[i] = dp1[i] + dp2[i] - 1;
            }
            
        }
        
         // finding maximum length mountain sub array 

        int mountainLen = dp3[0];
       
        for(int i=1; i<dp3.size(); i++){
            if(dp3[i] > mountainLen){
                mountainLen = dp3[i];
            }
        }
        
        int ans = nums.size() - mountainLen;

        return ans;
    }
};

int main(){


    return 0;
}