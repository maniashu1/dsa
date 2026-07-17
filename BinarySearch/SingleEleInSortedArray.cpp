
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

// Optimise Approach using Binary Search . T.C -> O(log n)


class Solution {
public:
    
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];    // if array has only one elements 
        if(nums[0] != nums[1]) return nums[0];  // if 1st element is the single element 
        if(nums[n-1] != nums[n-2]) return nums[n-1];    // if last element is the single element 

        int lo = 1;
        int hi = n-2;
        int mid = -1;

        // we are talking about indexes
        // (even,odd) -> element is on right half , eleminate Left
        // (odd,evem) -> element id in left half , eleminate Right 

        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
                return nums[mid];
            }
            // we are in left half
            if(mid%2==1 && nums[mid] == nums[mid-1] || mid%2==0 && nums[mid] == nums[mid+1]){
                lo = mid+1;
            } else {  // we are on wright half 
                hi = mid-1;
            }
        }
        return -1;

    }
};


int main(){


    return 0;
}