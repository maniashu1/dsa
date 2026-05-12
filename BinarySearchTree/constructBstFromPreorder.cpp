
// leetcode 1008 ( construct binary tree from preorder traversal ) medium

#include<iostream>
#include<vector>
using namespace std;

class TreeNode{
      public:
      int val;
      TreeNode* left;
      TreeNode* right;
      TreeNode(int val){
        this->val = val;
        this->left = NULL;
        thia->right = NULL;
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
       TreeNode* root = new TreeNode(preorder[0]);
       for(int i=1; i<preorder.size(); i++){
           insertIntoBST(root, preorder[i]);
       }
       return root;
    }

int main(){

    return 0;
}