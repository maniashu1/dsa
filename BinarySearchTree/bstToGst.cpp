
// leetcode 1038 ( Binary search tree to greater sum tree ) medium

#include<iostream>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

class Solution {
public: 
    int sum = 0;
    void reverseInorder(TreeNode* root){
        if(root == NULL) return;
        reverseInorder(root->right);
        root->val += sum;
        sum = root->val;
        reverseInorder(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        reverseInorder(root);
        return root;
    }
};

int main(){

    return 0;
}