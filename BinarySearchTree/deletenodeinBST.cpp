// leetcode 450 ( delete node from a binary search tree )

#include<iostream>
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

TreeNode* iop(TreeNode* root){
        if(root == NULL) return NULL;
        if(root->left!=NULL){
            root = root->left;
        }
        while(root->right!=NULL){
            root = root->right;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root->val == key){
            // case 1 : node has 0 child
            if(root->left == NULL && root->right == NULL){
                return NULL;
            } // case : 2 node has 1 child
             else if(root->left==NULL || root->right==NULL){
                if(root->left == NULL) return root->right;
                else return root->left;
            }  // case 3 : node has 2 child node
            else {
                TreeNode* pred = iop(root);
                root->val = pred->val;
                root->left = deleteNode(root->left,pred->val);
            }
        } else if(root->val > key){ // go in left subtree
              root->left = deleteNode(root->left,key);
        } else {
            root->right = deleteNode(root->right,key);
        }
        return root;
    }

int main(){


    return 0;
}