
//Leetcode  413  ( Airthemetic Slices ) Medium 

// Application of lis
// Bottom up approach

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n,0);
        if(n < 3) return 0; // if given array length is less than 3

        for(int i=2; i<n; i++){
            if(nums[i]-nums[i-1] == nums[i-1]-nums[i-2]){
                dp[i] = dp[i-1]+1;            }
        }
        
        // counting number of subarrays 
        int ans = 0;
        for(int i=0; i<n; i++){
            ans += dp[i];
        }
        
        return ans;
    }
};

int main(){


    return 0;
}