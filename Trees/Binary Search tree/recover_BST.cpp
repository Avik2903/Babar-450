#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Node structure
class Node{
  public:
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data = x;
        left = right = nullptr;
    }
};

// Calculate  Height
int getHeight(Node* root, int h) {
    if (root == nullptr) return h - 1;
    return max(getHeight(root->left, h + 1), 
                       getHeight(root->right, h + 1));
}

// Print Level Order
void levelOrder(Node* root) {
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    int lastLevel = 0;

    // function to get the height of tree
    int height = getHeight(root, 0);

    // printing the level order of tree
    while (!q.empty()) {
        auto top = q.front(); q.pop();
        Node* node = top.first;
        int lvl = top.second;

        if (lvl > lastLevel) {
            cout << "";
            lastLevel = lvl;
        }

        // all levels are printed
        if (lvl > height) break;

        
        if (node->data != -1) cout << node->data << " ";
        
        // printing null node
        else cout << "N ";

        // null node has no children
        if (node->data == -1) continue;

        if (node->left == nullptr) q.push({new Node(-1), lvl + 1});
        else q.push({node->left, lvl + 1});

        if (node->right == nullptr) q.push({new Node(-1), lvl + 1});
        else q.push({node->right, lvl + 1});
    }
}

// Function to store the inorder traversal 
void findInorder(Node* curr, vector<int>&inorder){
    if(curr == nullptr) return;

    findInorder(curr->left, inorder);

    inorder.push_back(curr->data);
    findInorder(curr->right, inorder);
}

// Recursive function to correct the BST by replacing
// node values with sorted values
void correctBSTUtil(Node* root, vector<int> &inorder, int &index){
    if(root == nullptr) return;
    correctBSTUtil(root->left, inorder, index);
    root->data = inorder[index];
    index++;
    correctBSTUtil(root->right, inorder, index);
}

// Function to fix the given BST 
void correctBST(Node* root){
    vector<int> inorder;
    findInorder(root, inorder);
    sort(inorder.begin(), inorder.end());
  
    int index = 0;
    correctBSTUtil(root, inorder, index);
}



int main(){
  
    // Constructing the tree with swapped nodes
    //       6
    //     /  \
    //    10   2
    //   / \  / \
    //  1  3 7  12
  
    Node *root = new Node(6);
    root->left = new Node(10);
    root->right = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(12);
    root->right->left = new Node(7);

    correctBST(root);
    levelOrder(root);
 
    return 0;
}