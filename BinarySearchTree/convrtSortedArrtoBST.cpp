
// leetcode 108 ( convert sorted array to binary search tree) easy

#include<iostream>
#include<vector>
using namespace std;

class TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution {
public:
    TreeNode* helper(vector<int>& nums,int lo,int hi){
        if(lo > hi) return NULL;
        int mid = lo + (hi-lo)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums,lo,mid-1);
        root->right = helper(nums,mid+1,hi);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        return helper(nums,lo,hi);
    }
};

int main(){

    return 0;
}