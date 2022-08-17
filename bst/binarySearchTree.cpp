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

bool isBst(node* root, int min, int max) {
    if(root == NULL) return true;
    //check if root ka data min se bada aur max chota he toh, make recursive call.
    if(root->data > min and root->data < max){
        bool left = isBst(root, min, root>data);
        bool right = isBst(root, root->data, max);
        return left && right;
    }
    return false;
}

node* buildTreeBST(node* root, int d) {
    if(root ==  NULL) {
        root = new node(d);
        return root;
    }
    if(d > root -> data) {
        root -> right = buildTreeBST(root->right, d);
    } else {
        root -> left = buildTreeBST(root->left, d);
    }
    return root;
}

void inorder(node* root) {
    if(root == NULL) return;
    inorder(root -> left);
    cout << root -> data <<" ";
    inorder(root -> right);
}

void buildTree(node* &root) {
    int d;
    cin >> d;
    while(d != -1) {
        root = buildTreeBST(root, d);
        cin >> d;
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

node* minVal(node* root) {
    node* temp = root;
    while(temp->left) {
        temp = temp -> left;
    }
    return temp;
}

node* maxVal(node* root) {
    node* temp = root;
    while(temp->right) {
        temp = temp -> right;
    }
    return temp;
}

node* deleteNode(node* root, int key) {
        if(!root) return nullptr;
        if(root->val < key)
            root->right = deleteNode(root->right, key);
        else if(root->val > key)
            root->left = deleteNode(root->left, key);
        else {
            // 0 child
            if(!root -> left and !root->right) {
                return nullptr;
            }
            //1 child

            // if only right child exist
            else if(!root -> left) {
                return root->right;
            }
            // if only left child exist
            else if(!root -> right) {
                return root->left;
            }
            // two child
            else {
                node* temp = root->right;
                while(temp -> left){
                    temp = temp -> left;
                }
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }
        }
    return root;
}

int main(){
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node* root = NULL;
    buildTree(root);
    inorder(root);
    cout << endl;
    leverl(root);
    // postorder(root);
    // cout << endl;
}