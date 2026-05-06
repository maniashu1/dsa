
// Leetcode 103 ( Binary tree Zig Zag level order traversal )  medium 

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


// calculating the levels
    int levels(TreeNode* root) {
        if (root == NULL)
            return 0;
        else
            return 1 + max(levels(root->left), levels(root->right));
    }

    // calculating the nth level
    void nthlevel(TreeNode* root, int curr, int val, vector<int>& v) {
        if (root == NULL)
            return;
        if (val % 2 == 0) {
            if (curr == val) {
                v.push_back(root->val);
                return;
            }
            nthlevel(root->right, curr + 1, val, v);
            nthlevel(root->left, curr + 1, val, v);
        } else {
            if (curr == val) {
                v.push_back(root->val);
                return;
            }
            nthlevel(root->left, curr + 1, val, v);
            nthlevel(root->right, curr + 1, val, v);
        }
    }

    void lorder(TreeNode* root, vector<vector<int>>& ans) {
        int n = levels(root);

        for (int i = 1; i <= n; i++) {
            vector<int> v;
            nthlevel(root, 1, i, v);
            ans.push_back(v);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        lorder(root, ans);
        return ans;
    }


    int main(){

        return 0;
    }