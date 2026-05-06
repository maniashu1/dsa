#include<iostream>
#include<queue>
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

// creating a display function.  
void display(TreeNode* root){
    if(root == NULL) return;
    cout << root->val << " ";
    display(root->left);
    display(root->right);
}

// level order treaversal using queue data structure.   using BFS - technique
void levelOrderTraversal(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* temp = new TreeNode(100);
    while(q.size() >  0){
        temp = q.front();
        q.pop();
        cout << temp->val << " ";
        if(temp->left != NULL) q.push(temp->left);    // interchange line 35 and 36 to print in reverse order 
        if(temp->right != NULL) q.push(temp->right);
    } 
  cout << endl;
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

   //display(a) ;
    cout << endl ;

    levelOrderTraversal(a);

    
    return 0;
}