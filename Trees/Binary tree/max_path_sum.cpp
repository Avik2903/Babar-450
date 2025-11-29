#include <bits/stdc++.h>
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

int maxipath(Node* node,int &maxi)
{
    if(!node)
        return 0;

    int left=max(0,maxipath(node->left,maxi));
    int right = max(0,maxipath(node->right,maxi));
    maxi=max(maxi,left+right+node->data);
    return max(left,right)+node->data;
}

int findMaxSum(Node* root)
{
    int maxi = INT_MIN;
    maxipath(root,maxi);
    return maxi;
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(10);
    root->left->left = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(-25);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(4);

    cout << findMaxSum(root);
    return 0;
}