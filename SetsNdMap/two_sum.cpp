// Leetcode 1  ( Two sum )

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

    vector<int> twoSum(vector<int>& nums, int target) {

        // brute force soln
   /*     
        int n = nums.size();
        vector<int> ans;
        for(int i = 0 ; i < n - 1; i++){
            for(int j = i + 1 ; j < n; j++){
                if(nums[i] + nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                } 
            }
        }
        return ans ;
     */

     // soln using hash maP

     vector<int> ans;
     int n = nums.size();
     unordered_map<int,int> m;

     for(int i = 0 ; i < n ; i++){
        int rem = target - nums[i];
        if(m.find(rem) != m.end()){
          ans.push_back(m[rem]);
          ans.push_back(i);
        }
        else m[nums[i]] = i;
     }   
     return ans;
    }

    int main(){

        return 0;
    }

