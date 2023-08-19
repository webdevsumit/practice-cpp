
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_set>

using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


void flatten(TreeNode* root) {
    if(root==NULL) return;
    flatten(root->left);
    flatten(root->right);
    if(root->left){
        TreeNode * r = root->right;
        root->right = root->left;
        root->left = NULL;

        while(root->right) root = root->right;
        root->right = r;
    }
}

TreeNode* buildtree(){
  int d;
  cin>>d;
  TreeNode*root;
  if(d==-1){
    return NULL;
  }
  root=new TreeNode(d);
  root->left=buildtree();
  root->right=buildtree();
  return root;
}
void print(TreeNode*root){
  if(root==NULL){
    return;
  }
  cout<<root->val<<" ";
  print(root->left);
  print(root->right);
}


void morrisTraversalPreorder(TreeNode* root){
  while(root){
    if(root->left == NULL){
      cout<<root->val<<" ";
      root = root->right;
    }else{
      TreeNode* current = root->left;
      while(current->right && current->right != root){
        current = current->right;
      }
      if(current->right == root){
        current->right = NULL;
        root = root->right;
      }else{
        cout<<root->val<<" ";
        current->right = root;
        root = root->left;
      }
    }
  }
}


int main(){
    TreeNode*root=buildtree();  
    // print(root);
    morrisTraversalPreorder(root);

    // cout<<"\n ANS : \n"; 
    // flatten(root);

    // print(root);

    return 0;
}