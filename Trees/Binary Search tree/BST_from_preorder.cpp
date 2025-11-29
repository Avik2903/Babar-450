#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// A recursive function to construct BST from pre[].
// idx is used to keep track of index in pre[].
Node *constructUtil(vector<int> &pre, int &idx, 
                             int min, int max)
{
    if (idx >= pre.size())
        return nullptr;
    
    int key = pre[idx]; 
    if (key <= min || key >= max)
        return nullptr;

    // If current element of pre[] is in range,
    // then only it is part of the current subtree
    Node *root = new Node(key);
    idx++;

    // All nodes in range {min .. key} 
    // go to the left subtree
    if (idx < pre.size())
        root->left = constructUtil(pre, idx, min, key);

    // All nodes in range {key .. max}
    // go to the right subtree
    if (idx < pre.size())
        root->right = constructUtil(pre, idx, key, max);
  
    return root;
}

// The main function to construct BST from
// given preorder traversal.
Node *constructTree(vector<int> &pre)
{
    int idx = 0;
    return constructUtil(pre, idx, INT_MIN, INT_MAX);
}

// A utility function to print inorder
// traversal of a Binary Tree
void inorder(Node *node)
{
    if (node == nullptr)
        return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

// Driver code
int main()
{
    vector<int> pre = {10, 5, 1, 7, 40, 50};
    Node *root = constructTree(pre);
    inorder(root);
    return 0;
}