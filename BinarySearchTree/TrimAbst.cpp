
// leetcode 669 ( Trimming a binary search tree ) medium

#include<iostream>
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


TreeNode* trim(TreeNode* root,int low, int high){
        if(root == NULL) return NULL;
        while(root->left != NULL){
            if(root->left->val < low){
                root->left = root->left->right;
            }
            else if(root->left->val > high){
                root->left = root->left->left;
            } else break;
        }
        while(root->right != NULL){
            if(root->right->val > high){
                root->right = root->right->left;
            }
            else if(root->right->val < low){
                root->right = root->right->right;
            } else break;
        }
        trim(root->left,low,high);
        trim(root->right,low,high);
        return root;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode* dummy = new TreeNode(INT_MAX);
        dummy->left = root;
        trim(dummy,low,high);
        return dummy->left;
    }

int main(){

    return 0;
}