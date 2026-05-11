
// leetcode 701 ( insertiomn into bonary search tree ) medium

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

TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        else if(root->val > val){   // go left side of th tree
            if(root->left == NULL){
                TreeNode* temp = new TreeNode(val);
                root->left = temp;
                return root;
            } else {
                insertIntoBST(root->left,val);
            }
        } else {        // go right side of the tree
            if(root->right == NULL){
                TreeNode* temp = new TreeNode(val);
                root->right = temp;
                return root;
            }
            else {
                insertIntoBST(root->right,val);
            }
        }
        return root;
    }

int main(){



    return 0;
}