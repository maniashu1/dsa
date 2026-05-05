// Leetcode 236 ( lowest common ancesstor )


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
        this->right = NULL;
    }
};

bool exists(TreeNode* root , TreeNode* target){
        if(root == NULL) return false;
        if(root == target) return true;
        return (exists(root->left,target) || exists(root->right,target));

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q) return root;
        else if(exists(root->left , p) && exists(root->right , q)) return root; // p and q present in left and right subtree respectively
        else if(exists(root->right ,p) && exists(root->left , q)) return root;  // p and q present in right and left subtree respectively
        else if(exists(root->left,p) && exists(root->left,q)) return lowestCommonAncestor(root->left,p,q);
        else return lowestCommonAncestor(root->right,p,q);
    }


int main(){


    return 0;
}