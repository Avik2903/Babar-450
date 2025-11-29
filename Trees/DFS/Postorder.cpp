#include<bits/stdc++.h>
using namespace std;
class Node{
    public: 
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data= val;
        left = right = NULL;
    }
};

void PostOrder(Node* root, vector<int>& res)
{
    if(root==nullptr)
        return;
    PostOrder(root->left,res);
    PostOrder(root->right,res);
    res.push_back(root->data);
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    vector<int> res;
    PostOrder(root, res);
    for(int node : res) 
        cout << node << " ";
    return 0;
}