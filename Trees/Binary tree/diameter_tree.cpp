/*#include <iostream>   /// O(n^2)
#include <algorithm>
using namespace std;

// Node Structure
class Node {
public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

// Function to compute the height of a tree.
int height(Node* root) {
  
    if (root == nullptr)
        return 0;

    // If tree is not empty then height = 1 +
    // max of left height and right heights
    return 1 + max(height(root->left), 
                   height(root->right));
}

// Function to get diameter of a binary tree
int diameter(Node* root) {
  
    if (root == nullptr)
        return 0;

    // Get the height of left and right
  	// sub-trees
    int lheight = height(root->left);
    int rheight = height(root->right);

    // Get the diameter of left and right
  	// sub-trees
    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);

    return max({lheight + rheight, ldiameter, rdiameter});
}

int main() {

    Node* root = new Node(5);
    root->left = new Node(8);
    root->right = new Node(6);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
  	root->right->left = new Node(9);
    cout << diameter(root) << endl;

    return 0;
}*/

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
int maxDiameter=0;
int diameterRecur(Node* root) {
    if (!root)
        return 0;
    int lHeight = diameterRecur(root->left);
    int rHeight = diameterRecur(root->right);
    if (lHeight + rHeight > maxDiameter)
        maxDiameter = lHeight + rHeight;
    return 1 + max(lHeight, rHeight);
}

int diameter(Node* root)
{
    maxDiameter=0;
    diameterRecur(root);
    return maxDiameter;
}

int main() {
    // Constructed binary tree:
    //          5
    //        /   \
    //       8     6
    //      / \   /
    //     3   7 9

    Node* root = new Node(5);
    root->left = new Node(8);
    root->right = new Node(6);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(9);

    cout << diameter(root) << endl;

    return 0;
}