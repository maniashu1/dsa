
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


class Solution {
public:

    // Optimised Binary search approach . T.C -> O(log n)

    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0; // if array has only one element
        if(nums[0] > nums[1]) return 0; // First element is a peak element 
        if(nums[n-1] > nums[n-2]) return n-1; // last element is a peak element 
        int lo = 1;
        int hi = n-2;
        int mid = -1;
        while(lo <= hi){
            mid = lo + (hi-lo)/2;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){  // mid is a peak element 
                return mid;
            }
            if(nums[mid] > nums[mid-1]){  // peak is in right side ans mid is on increasing curve 
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }
        return 0;
        
    }
};

int main(){

    return 0;
}