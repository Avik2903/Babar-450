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

int depth(Node* root)
{
    if(root== NULL)
    return 0;

    int lh= depth(root->left);
    int rh= depth(root->right);
    return 1+max(lh,rh);
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout<<depth(root);

    return 0;
}