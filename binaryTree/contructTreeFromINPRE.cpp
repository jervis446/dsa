//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    private: 
    int findPos(int in[], int el, int n) {
        for(int i=0;i<n;i++) 
            if (in[i] == el)  return i;
        return -1;
    }
    Node* helper(int in[],int pre[], int &index, int l, int r, int n) {
        if(index >= n || l>r) return NULL;
        // check first index on preorder
        int el = pre[index++];
        Node* root = new Node(el);
        // find that position in inorder array
        int pos = findPos(in,el,n);
        
        //recursive calls for 
        root -> left = helper(in,pre,index, l,pos-1,n);
        root -> right = helper(in,pre,index, pos+1, r,n);
        return root;
    }
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int index = 0;
        Node* ans = helper(in,pre,index, 0,n-1,n);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends