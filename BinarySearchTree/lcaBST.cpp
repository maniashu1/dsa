
// leetcode 235 ( lowest common ancesstor of a binary search tree)


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


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val == p->val || root->val == q->val) return root;
        else if(root->val > p->val && root->val < q->val) return root;
        else if(root->val < p->val && root->val > q->val) return root;
        else if(root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left,p,q);
        else return lowestCommonAncestor(root->right,p,q);
    }

int main(){


    return 0;
}
