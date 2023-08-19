#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int pseudoPalindromicPaths (TreeNode* root, int count=0) {
    if (!root)
        return 0;
    count ^= 1 << root->val;
    
    int res = pseudoPalindromicPaths(root->left, count) + pseudoPalindromicPaths(root->right, count);
    
    if (!root->left && !root->right && (count & (count - 1)) == 0)
        res++;
    return res;
    
}

TreeNode * buildTree(TreeNode * root){
    cout << "Enter the val : " << endl;
    int val;
    cin>> val;

    if(val == -1){
        return NULL;
    }
    root = new TreeNode(val);

    cout<< "Enter val for left child of "<< val << endl;
    root->left = buildTree(root->left);
    cout<< "Enter val for right child of "<< val << endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(TreeNode * root){
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        TreeNode * temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<< endl;
            if(!q.empty()) q.push(NULL);
        }else{
            cout << temp -> val << " ";
            if(temp -> left){
                q.push(temp -> left);
            }
            if(temp -> right){
                q.push(temp -> right);
            }
        }

    }
}

void buildFromLevelOrder(TreeNode * &root){
    queue<TreeNode*> q;
    cout<< "Enter val for root" << endl;
    int val; 
    cin>> val;
    root = new TreeNode(val);
    q.push(root);

    while(!q.empty()){
        TreeNode * temp = q.front();
        q.pop();

        cout<< "Enter left TreeNode for : "<< temp -> val << endl;
        int leftNode;
        cin>> leftNode;
        if(leftNode != -1){
            temp -> left = new TreeNode(leftNode);
            q.push(temp -> left);
        }

        cout<< "Enter right TreeNode for : "<< temp -> val << endl;
        int rightNode;
        cin>> rightNode;
        if(rightNode != -1){
            temp -> right = new TreeNode(rightNode);
            q.push(temp -> right);
        }


    }
}

int main(){
    
    // 1 9 1 -1 1 -1 1 -1 -1 7 -1 -1 4 -1 -1

    TreeNode* root = NULL;
    buildFromLevelOrder(root);
    
    // levelOrderTraversal
    levelOrderTraversal(root);

    int ans = pseudoPalindromicPaths(root);

    // levelOrderTraversal
    cout<<"ANS : "<<ans<<endl;

    return 0;
}