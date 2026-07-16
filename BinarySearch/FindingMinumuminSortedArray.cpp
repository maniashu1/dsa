
// Leetcode 153 ( Finding minumum in rotated sorted array ) Medium

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size() - 1;
        int ans = INT_MAX;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] >= nums[lo]) {
                ans = min(ans, nums[lo]);   // left half is sorted
                lo = mid + 1;
            } else {
                ans = min(ans, nums[mid]);  // pivot is in left half
                hi = mid - 1;
            }
        }

        return ans;
    }
};

int main(){

    return 0;
}