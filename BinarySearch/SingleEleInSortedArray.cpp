
// Leetcode 540 ( Single element in sorted array ) Medium

#include<iostream>
#include<vector>
using namespace std;

// Brute force approach -> O(n)

class Solution {
public:
    
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        for(int i=0; i<n; i++){
            if(i == 0){
                if(nums[i] != nums[1]) return nums[0];
            }
            else if(i == n-1){
                if(nums[n-1] != nums[n-2]) return nums[n-1];
            }
            else {
                if(nums[i] != nums[i-1] && nums[i] != nums[i+1])
                  return nums[i];
            }
        
        }
        return -1;
    }
};



int main(){


    return 0;
}