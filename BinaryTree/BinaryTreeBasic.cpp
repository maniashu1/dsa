#include<iostream>
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

// creating a display function
void display(TreeNode* root){
    if(root == NULL) return;
    cout << root->val << " ";
    display(root->left);
    display(root->right);
}

// clculatig sum of the tree
int sum(TreeNode* root){
    if(root == NULL) return 0;
    return root->val + sum(root->left) + sum(root->right);
}

// clculatig size of the tree
int size(TreeNode* root){
    if(root == NULL) return 0;
    return 1 + size(root->left) + size(root->right);
}

// finding maximum element in the tree
int maxInTree(TreeNode* root){
    if(root == NULL) return INT_MIN;    // INT_MIN is useful when value is -ve
    int leftMax = maxInTree(root->left);
    int rightMax = maxInTree(root->right);
    return max(root->val, max(leftMax , rightMax));
}

// finding minimum element in the tree
int minInTree(TreeNode* root){
    if(root == NULL) return INT_MAX;    // INT_MIN is useful when value is -ve
    int leftMin = minInTree(root->left);
    int rightMin = minInTree(root->right);
    return min(root->val, min(leftMin , rightMin));
}

// finding the level of the tree
int levels(TreeNode* root){
    if(root == NULL) return 0;   
    return 1 + max(levels(root->left) , levels(root->right));
}


int main(){

    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    TreeNode* d = new TreeNode(4);
    TreeNode* e = new TreeNode(5);
    TreeNode* f = new TreeNode(6);
    TreeNode* g = new TreeNode(7);
    
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    display(a) ;
    cout << endl ;

    cout << "The sum of all the tree node value is : " << sum(a) << endl;

    cout << "The size of tree is : " << size(a) << endl;

    cout << "The maximum element of tree is : " << maxInTree(a) << endl;

    cout << "The minimum element of tree is : " << minInTree(a) << endl;

    cout << "The no of levele present in the tree is : " << levels(a) << endl;

    cout << "The height of the tree is : " << levels(a) - 1 << endl;


    return 0;
}