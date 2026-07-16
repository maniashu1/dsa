
// Leetcode 33 ( Search in rotated sorted array ) Medium

// O(log n) approach uing binary search 
// using linear search it goes O(n)


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0 ;
        int hi = n-1;
        int mid = -1;

        while(lo<=hi){

            mid = lo + (hi-lo)/2;
            if(target == nums[mid]){
                return mid;
            }

            // left side is sorted 
            if(nums[lo] <= nums[mid]){
               if(target >= nums[lo] && target <= nums[mid]){  // taregt lies in left side 
                   hi = mid-1;
               } else {
                lo = mid+1;
               }
            } else { // write side is sorted 
                if(target >= nums[mid] && target <= nums[hi]){ // target lies in right side 
                    lo = mid+1;
                } else {
                    hi = mid-1;
                }
            }

        }

        return -1;
    }
};

int main(){

    return 0;
}