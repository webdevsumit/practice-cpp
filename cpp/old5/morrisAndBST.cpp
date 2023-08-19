#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

        node(int d){
            this -> data = d;
            this -> left = NULL;
            this -> right = NULL;
        }
};

void levelOrderTraversal(node * root){
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node * temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<< endl;
            if(!q.empty()) q.push(NULL);
        }else{
            cout << temp -> data << " ";
            if(temp -> left){
                q.push(temp -> left);
            }
            if(temp -> right){
                q.push(temp -> right);
            }
        }

    }
}

void inorder(node * root){
    // base case
    if(root == NULL){
        return;
    }

    inorder(root -> left);
    cout<< root -> data << " ";
    inorder(root -> right);
}

void preorder(node * root){
    // base case
    if(root == NULL){
        return;
    }

    cout<< root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

void postorder(node * root){
    // base case
    if(root == NULL){
        return;
    }

    postorder(root -> left);
    postorder(root -> right);
    cout<< root -> data << " ";
}

void buildFromLevelOrder(node * &root){
    queue<node*> q;
    cout<< "Enter data for root" << endl;
    int data; 
    cin>> data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node * temp = q.front();
        q.pop();

        cout<< "Enter left node for : "<< temp -> data << endl;
        int leftNode;
        cin>> leftNode;
        if(leftNode != -1){
            temp -> left = new node(leftNode);
            q.push(temp -> left);
        }

        cout<< "Enter right node for : "<< temp -> data << endl;
        int rightNode;
        cin>> rightNode;
        if(rightNode != -1){
            temp -> right = new node(rightNode);
            q.push(temp -> right);
        }
        
    }
}

void morrisTraversal(node * root){
    node* current = NULL;
    node* pre = NULL;

    if(root == NULL){
        return;
    }

    current = root;

    while(current != NULL){

        if(current->left == NULL){
            cout<< current->data<<" ";
            current = current->right;
        }
        else{

            pre = current->left;
            while (pre->right != NULL && pre->right != current){
                pre = pre->right;
            } 
            
            if(pre->right == NULL){
                pre->right = current;
                current = current->left;
            }

            else{
                pre->right = NULL;
                cout<< current->data<<" ";
                current = current->right;
            }
            
        }
    }
    cout<<endl;
}

node* insertIntoBST(node* root, int d){
    if(root == NULL){
        root = new node(d);
        return root;
    }

    if(d > root->data){
        root->right = insertIntoBST(root->right, d);
    }else{
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}

void takeInput(node* &root){
    int data;
    cout<< "Enter Values : ";
    cin>> data;

    if(data == -1) return;

    while(data != -1){
        root = insertIntoBST(root, data);
        cin>>data;
    }
}

node * deleteFromBST(node* root, int val){
    //base case

    if(root == NULL){
        return root;
    }

    if(root->data == val){
        // 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // 1 child -- left
        if(root->left != NULL && root->right == NULL){
            node* temp = root->left;
            delete root;
            return NULL;
        }

        // 1 child -- right
        if(root->left == NULL && root->right != NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if(root->left != NULL && root->right != NULL){
            node* temp = root->left;
            while(temp->right){
                temp = temp->right;
            }
            root->data = temp->data;
            root->left = deleteFromBST(root->left, temp->data);
            return root;
        }

    }
    else if(root->data > val){
        // Data in left part
        root->left = deleteFromBST(root->left, val);
    }
    else{
        // Data in right part
        root->right = deleteFromBST(root->right, val);
    }

    return root;
}

int main(){

    node* root = NULL;

    // creating tree with buildFromLevelOrder
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // buildFromLevelOrder(root);

    // creating tree with buildFromLevelOrder
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    takeInput(root);
    
    // levelOrderTraversal
    // levelOrderTraversal(root);

    // Morris traversal
    morrisTraversal(root);

    root = deleteFromBST(root, 30);

    morrisTraversal(root);

    return 0;
}