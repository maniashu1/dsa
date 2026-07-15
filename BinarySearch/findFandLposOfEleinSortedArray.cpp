
// Leetcode 34 ( Find first and last position of element in sorted array ) Medium

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        if (n == 0)
            return {-1, -1};

        int lo = 0, hi = n - 1, mid;

        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;

            if (nums[mid] == target)
                break;
            else if (nums[mid] < target)
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        // Target not found
        if (lo > hi)
            return {-1, -1};

        int si = mid, ei = mid;

        while (si >= 0 && nums[si] == target)
            si--;

        while (ei < n && nums[ei] == target)
            ei++;

        return {si + 1, ei - 1};
    }
};
    

int main(){


    return 0;
}