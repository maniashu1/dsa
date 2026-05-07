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

// preorder traversal.  root - left - right
void preorder(TreeNode* root){
    if(root == NULL) return ;
    cout<< root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// inorder traversal.     left - root - right
void inorder(TreeNode* root){
    if(root == NULL) return ;
    inorder(root->left);
    cout<< root->val << " ";
    inorder(root->right);
}

// postorder traversal.  left - right - root
void postorder(TreeNode* root){
    if(root == NULL) return ;
    postorder(root->left);
    postorder(root->right);
    cout<< root->val << " ";
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

    cout << "preorder traversal:  ";
    preorder(a);
    cout << endl;

    cout << "Inorder traversal : ";
    inorder(a);
    cout << endl;

    cout << "Postorder traversal : ";
    postorder(a);

    return 0;
}