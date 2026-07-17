
// Leetcode 162 ( Finding Peak Element ) Medium

#include<iostream>
#include<vector>
using namespace std;

 // Brute force approach . T.C -> O(n)

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        if(n == 2) {
            if(nums[0] > nums[1]){
                return 0;
            } return 1;
        }
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;
        for(int i=1; i<n-1; i++){
            if(nums[i]>nums[i-1] && nums[i] > nums[i+1]){
                return i;
            }
        }
         
        return 0;
        
    }
};

int main(){

    return 0;
}