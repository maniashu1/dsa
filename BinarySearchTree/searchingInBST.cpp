
// leetcode 700 ( searching element in binary search tree)

#include<iostream>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val=val;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL) return NULL;
        if(root->val == val) return root;
        if(root->val > val) return searchBST(root->left,val);
        else return searchBST(root->right,val);
    }

int main(){



    return 0;
}