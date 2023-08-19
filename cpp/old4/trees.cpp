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

node * buildTree(node * root){
    cout << "Enter the data : " << endl;
    int data;
    cin>> data;

    if(data == -1){
        return NULL;
    }
    root = new node(data);

    cout<< "Enter data for left child of "<< data << endl;
    root->left = buildTree(root->left);
    cout<< "Enter data for right child of "<< data << endl;
    root->right = buildTree(root->right);

    return root;
}

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

void reverseLevelOrderTraversal(node * root){
    queue<node *> q;
    stack<node *> s;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node * temp = q.front();
        q.pop();

        if(temp == NULL){
            // cout<< endl;
            s.push(NULL);
            if(!q.empty()) q.push(NULL);
        }else{
            // cout << temp -> data << " ";
            s.push(temp);
            if(temp -> right){
                q.push(temp -> right);
            }
            if(temp -> left){
                q.push(temp -> left);
            }
        }

    }
    while(!s.empty()){
        node * temp = s.top();
        s.pop();

        if(temp == NULL){
            cout<< endl;
        }else{
            cout << temp -> data << " ";
        }

    }
}

vector<vector<int>> levelOrderBottom(node* root) {
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        
        queue<node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            vector<int> r;
            
            for(int i=0; i<n; i++)
            {
                node* temp = q.front();
                r.push_back(temp->data);
                
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                q.pop();
            }
            res.push_back(r);    
        }
        reverse(res.begin(), res.end());
        return res;
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

int main(){

    node* root = NULL;

    // creating tree;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // root = buildTree(root);

    // creating tree with buildFromLevelOrder
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    buildFromLevelOrder(root);
    
    // levelOrderTraversal
    levelOrderTraversal(root);

    // reverseLevelOrderTraversal
    // reverseLevelOrderTraversal(root);

    // inorder
    // inorder(root);
    // cout<<endl;

    // preorder
    // preorder(root);
    // cout<<endl;

    // postorder
    // postorder(root);
    // cout<<endl;

    return 0;
}