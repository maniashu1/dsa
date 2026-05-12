
// leetcode 98 ( validate vinary search tree ) medium

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

    }
}

void inorder(TreeNode* root, vector<int>& v){
        if(root == NULL) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
}
bool isValidBST(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        int n = v.size();
        for(int i=1; i<n; i++){
            if(v[i] <= v[i-1]){
                return false;
            } 
        }
        return true;
}


    int main(){

        return 0;
    }