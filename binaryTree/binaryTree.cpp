#include <iostream>
#include <queue>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;
    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root){
    int data;
    cin >> data;
    root = new node(data);
    if(data == -1) return NULL;
    cout << "Enter data for inseting in left of: "<<data <<endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inseting in right of: "<<data <<endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(node* root) {
    queue <node*> q;
    q.push(root);
   // q.push(NULL);
    while(!q.empty()){
        node* temp = q.front();
        cout << temp -> data <<" ";
        q.pop();
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}

void leverl(node* root) {
    queue <node* > q;
    q.push(root);
    while(!q.empty()) {
        node* temp = q.front();
        q.pop();
        cout << temp->data <<endl;
        if(temp -> left) q.push(temp->left);
        if(temp -> right) q.push(temp->right);
    }
}
void inorder(node* root) {
    if(root == NULL) return;
    inorder(root -> left);
    cout << root -> data <<" ";
    inorder(root -> right);
}

void preorder(node* root) {
    if(root == NULL) return;
    cout << root -> data <<" ";
    inorder(root -> left);
    inorder(root -> right);
}

void postorder(node* root) {
    if(root == NULL) return;
    inorder(root -> left);
    inorder(root -> right);
    cout << root -> data <<" ";
}

int main(){
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node* root = NULL;
    root = buildTree(root);
    postorder(root);
    cout << endl;
}