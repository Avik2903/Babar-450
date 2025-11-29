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

void InOrder(Node* root, vector<int>& res)
{
    if(root==nullptr)
        return;
    InOrder(root->left,res);
    res.push_back(root->data);
    InOrder(root->right,res);
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    vector<int> res;
    InOrder(root, res);
    for(int node : res) 
        cout << node << " ";
    return 0;
}