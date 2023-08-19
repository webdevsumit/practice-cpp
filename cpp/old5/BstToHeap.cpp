#include<iostream>
#include<queue>

using namespace std;
 
// Structure of a node of BST
struct Node {
 
    int data;
    Node *left, *right;
};
 
/* Helper function that allocates a new node
   with the given data and NULL left and right
   pointers. */
struct Node* getNode(int data)
{
    struct Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
 
// function prototype for preorder traversal
// of the given tree
void preorderTraversal(Node*);
 
// function for the inorder traversal of the tree
// so as to store the node values in 'arr' in
// sorted order
void inorderTraversal(Node* root, vector<int>& arr)
{   
    if(root == NULL) return;

    inorderTraversal(root -> left, arr);
    arr.push_back(root->data);
    inorderTraversal(root -> right, arr);

}
 
// function to convert the given BST to MIN HEAP
// performs preorder traversal of the tree
void BSTToMinHeap(Node* root, vector<int> arr, int &i)
{
    if (root == NULL) return;

    root->data = arr[++i];
    BSTToMinHeap(root -> left, arr, i);
    BSTToMinHeap(root -> right, arr, i);

}
 
// utility function to convert the given BST to
// MIN HEAP
void convertToMinHeapUtil(Node* root)
{
    if (root == NULL) return;

    vector<int> arr;
    inorderTraversal(root, arr);
    int i = -1;
    BSTToMinHeap(root, arr, i);
}
 
// function for the preorder traversal of the tree
void preorderTraversal(Node* root)
{
    if(root == NULL) return;

    cout << root->data << " ";
    preorderTraversal(root -> left);
    preorderTraversal(root -> right);
}
 
// Driver program to test above
int main()
{
    // BST formation
    struct Node* root = getNode(4);
    root->left = getNode(2);
    root->right = getNode(6);
    root->left->left = getNode(1);
    root->left->right = getNode(3);
    root->right->left = getNode(5);
    root->right->right = getNode(7);
 
    // Function call
    convertToMinHeapUtil(root);
    cout << "Preorder Traversal:" << endl;
    preorderTraversal(root);
 
    return 0;
}