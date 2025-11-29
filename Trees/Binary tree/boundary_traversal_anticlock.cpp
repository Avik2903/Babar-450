#include<bits/stdc++.h>
using namespace std;

// Node Structure
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

bool isLeaf(Node *node) {
    return node->left == nullptr && node->right == nullptr;
}

// Function to collect left boundary nodes
// (top-down order)
void collectLeft(Node* root, vector<int>& res) {
    
  	// exclude leaf node
    if (root == nullptr || isLeaf(root))
        return;
	
  	res.push_back(root->data);
    if (root->left) 
        collectLeft(root->left, res);
    
    else if (root->right)
        collectLeft(root->right, res);
}

// Function to collect all leaf nodes 
void collectLeaves(Node *root, vector<int> &res) {
    if (root == nullptr)
        return;
	
  	// Add leaf nodes
    if (isLeaf(root)) {
        res.push_back(root->data);
        return;
    }

    collectLeaves(root->left, res);
    collectLeaves(root->right, res);
}


// Function to collect right boundary nodes
// (bottom-up order)
void collectRight(Node* root, vector<int>& res) {
  	
  	// exclude leaf nodes
    if (root == nullptr || isLeaf(root)) 
        return;

    if (root->right)
        collectRight(root->right, res);

    else if (root->left) 
        collectRight(root->left, res);
	
	res.push_back(root->data);  
}

// Function to find Boundary Traversal of Binary Tree
vector<int> boundaryTraversal(Node *root) {
	vector<int> res;

    if (!root)
        return res;

    // Add root data if it's not a leaf
    if (!isLeaf(root))
        res.push_back(root->data);

    // Collect left boundary
    collectLeft(root->left, res); 

    // Collect leaf nodes
    collectLeaves(root, res);

    // Collect right boundary
    collectRight(root->right, res);

    return res;
}

int main() {

    // Input Binary tree
    //            1
    //         /     \
    //       2         3
    //     /   \     /   \
    //    4     5   6     7
    //         / \
    //        8   9
    
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);


    vector<int> boundary = boundaryTraversal(root);

    for (int x : boundary)
        cout << x << " ";

    return 0;
}