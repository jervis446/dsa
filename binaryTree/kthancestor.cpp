//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}
int kthAncestor(Node *root, int k, int node);

int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        int k , node;
        scanf("%d ",&k);
        scanf("%d ",&node);
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		cout<<kthAncestor(root,k,node)<<endl;
    }
    return 0;
}

// } Driver Code Ends


//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// We store the ancestor in a pre-order traversal manner 
// and ancestor of a node will not be its sibiling or subtree nodes 
//below node(for ancestor to be found) level. 
// That's why we store ancestor in pass-by-value manner.


// logic 1
// void helper(Node *root, int &k, int &node,int &data, vector <int> temp) {
//     if(!root) return ;
//     // only do traversal when ancestor not found.  
//         // store ancestor in the vector.
//     temp.push_back(root->data);
//     helper(root->left, k, node, data, temp);
//     helper(root->right, k, node, data, temp);
//     if(root->data == node){
//         // get the ancestor of the node using vector of ancestor.
//         int size = temp.size()-k-1;
//         if(size >= 0) {
//             data = temp[size];
//         }
//     }
// }
// logic 2
Node * helper(Node *root, int &k, int node) {
    if(!root) return NULL;
    // return matched root;
    if(root->data == node){
        return root;
    }
    Node* left = helper(root->left, k, node);
    Node* right = helper(root->right, k, node);
    if(left != NULL and right == NULL){
        k--;
        if(k<=0){
            // ans lock kardiya k ko ultra max karke
            k=INT_MAX;
            return root;
        }
        return left;
    }
    if(left == NULL and right != NULL){
         k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        return right;
    }
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    Node* ans = helper(root, k, node);
    // edge case if ancestor is root
    if(ans == NULL || ans->data == node){
        return -1;
    }
    else return ans->data;
    
}
