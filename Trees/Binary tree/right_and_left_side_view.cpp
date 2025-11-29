#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data=val;
        left=right=nullptr;
    }
};

void rightview(Node* root, int level,vector<int>& res)
{

    if(!root)
        return;

    if(level==res.size())
        res.push_back(root->data);

    rightview(root->right,level+1,res);
    rightview(root->left,level+1,res);
}

void leftview(Node* root, int level,vector<int>& res)
{

    if(!root)
        return;

    if(level==res.size())
        res.push_back(root->data);

    leftview(root->left,level+1,res);
    leftview(root->right,level+1,res);
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    vector<int> ans;
    //rightview(root,0,ans);
    leftview(root,0,ans);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    return 0;
}