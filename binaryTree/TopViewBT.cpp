#include <iostream>
#include <queue>
using namespace std;

class Node {
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

vector<int> topView(Node *root)
{
    vector <int> ans;
    if(root == NULL) return ans;
    map<int,int> m;
    queue <pair<Node*, int> > q;
    q.push(make_pair(root,0));
    while(!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();
        Node* front = temp.first;
        int hd = temp.second;
        if(m.find(hd) == m.end()){
            m[hd] = front->data;
        }
        if(front->left) q.push(make_pair(front->left,hd-1));
        if(front->right) q.push(make_pair(front->right,hd+1));
    }
    for(auto i: m) {
        ans.push_back(i.second);
    }
    return ans;
}