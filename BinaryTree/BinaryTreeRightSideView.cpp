// Leetcode 199 ( Binary tree right side view ) medium

#include<iostream>
#include<vector>
using namespace std;

// creating a tree node class
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


// finding levele
    int levels(TreeNode* root){
        if(root == NULL) return 0;
        else return 1 + max(levels(root->left),levels(root->right));
    }

    // pushing rightmost element of nth the level in the vector
    void nthlevel(TreeNode* root,int curr,int lev,vector<int>& ans){
        if(root == NULL) return;
        if(curr == lev){
           ans[curr] = root->val;
           return;
        }
        nthlevel(root->left,curr+1,lev,ans);
        nthlevel(root->right,curr+1,lev,ans);
    }


    // function to traverse for each level
    void lorder(TreeNode* root,vector<int>& ans){
        int n = ans.size();
        for(int i=0; i<n; i++){
            nthlevel(root,0,i,ans);
        }
    }
    
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans(levels(root),0);
        lorder(root,ans);
        return ans;
    }


    // more optimised
    int levels(TreeNode* root){
        if(root == NULL) return 0;
        else return 1 + max(levels(root->left),levels(root->right));
    }
    
    void preorder(TreeNode* root,vector<int>& ans,int level){
        if(root == NULL) return ;
        ans[level] = root->val;
        preorder(root->left,ans,level+1);
        preorder(root->right,ans,level+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans(levels(root),0);
        preorder(root,ans,0);
        return ans;
    }

    
    int main(){

        return 0;
    }