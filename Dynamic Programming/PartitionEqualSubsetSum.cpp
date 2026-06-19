
// Leetcode 416 ( Partition Equal Subset sum ) Medium

// same as Subset sum 
// here target becomes sum/2
// if we can find one subset of half sum then remaining element must form a subset of half sum

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    
    vector<vector<int>> dp;

    bool subsetSum(vector<int>& nums, int idx, int target){

         if(target == 0) return true;
         if(idx == nums.size()) return false;
        
         if(dp[idx][target] != -1) return dp[idx][target];

         bool dontPick = subsetSum(nums,idx+1,target);
         bool pick = false;
         if(nums[idx] <= target){
            pick = subsetSum(nums,idx+1,target-nums[idx]);
         }

         return dp[idx][target] = dontPick || pick;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        // if sum is odd then then it can not be achieved by subset partition
        if(sum % 2 != 0) return false; 
        
        int target = sum/2;

        dp.clear();
        dp.resize(205,vector<int>(target+1,-1));

        return subsetSum(nums,0,target);
    }
};

int main(){


    return 0;
}