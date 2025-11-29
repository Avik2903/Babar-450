#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *left,*right;
    Node(int val)
    {
        data=val;
        left=right=nullptr;
    }
};

int left_height(Node* node)
{
    int ht = 0;
    while (node) {
        ht++;
        node = node->left;
    }
    return ht;
}

int right_height(Node* node)
{
    int ht = 0;
    while (node) {
        ht++;
        node = node->right;
    }
    // Return the left height obtained
    return ht;
}

int TotalNodes(Node* root)
{
    // Base Case
    if (root == NULL)
        return 0;
    // Find the left height and the
    // right heights
    int lh = left_height(root);
    int rh = right_height(root);
    // If left and right heights are
    // equal return 2^height(1<<height) -1
    if (lh == rh)
        return (1 << lh) - 1;
    // Otherwise, recursive call
    return 1 + TotalNodes(root->left) + TotalNodes(root->right);
}


int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(9);
    root->right->right = new Node(8);
    root->left->left->left = new Node(6);
    root->left->left->right = new Node(7);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);

    cout<<TotalNodes(root);

    return 0;
}