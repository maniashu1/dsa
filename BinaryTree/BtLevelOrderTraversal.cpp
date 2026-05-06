// Leetcode (102) Binary tree level order traversal - medium 

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


int levels(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(levels(root->left) , levels(root->right));
    }
    void nthLevels(TreeNode* root , int curr , int val, vector<int>& v){
        if(root == NULL) return;
        if(curr == val){
            v.push_back(root->val);
            return;
        }
        nthLevels(root->left,curr+1,val,v);
        nthLevels(root->right,curr+1,val,v);
    }
    void lorder(TreeNode* root, vector<vector<int>>& ans){
        int n = levels(root);
        for(int i=1; i<=n; i++){
            vector<int> v;
            nthLevels(root,1,i,v);
            ans.push_back(v);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        lorder(root,ans);
        return ans;
    }