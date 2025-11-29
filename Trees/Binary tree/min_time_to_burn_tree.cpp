#include <iostream>
#include <unordered_map>
#include<algorithm>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

//  Recursively set parent for each node
void setParent(Node* root, unordered_map<int, Node*>& parent) {
    if (!root) return;
    if (root->left) {
        parent[root->left->data] = root;
        setParent(root->left, parent);
    }
    if (root->right) {
        parent[root->right->data] = root;
        setParent(root->right, parent);
    }
}

//  Recursively find target node
Node* findTarget(Node* root, int target) {
    if (!root) return nullptr;
    if (root->data == target) return root;

    Node* left = findTarget(root->left, target);
    if (left) return left;

    return findTarget(root->right, target);
}

//  DFS to calculate minimum time to burn entire tree
int dfs(Node* node, unordered_map<int,int>& visited, unordered_map<int, Node*>& parent) {
    if (!node || visited[node->data]) return 0;

    visited[node->data] = 1;
    
    // dfs call for left and right child
    int timeLeft = dfs(node->left, visited, parent);
    int timeRight = dfs(node->right, visited, parent);
    int timeParent = 0;

    // call dfs for parent if parnet is not visited
    if (parent.find(node->data) != parent.end())
        timeParent = dfs(parent[node->data], visited, parent);

    return max({timeLeft, timeRight, timeParent}) + 1;
}

int minTime(Node* root, int target) {
    unordered_map<int, Node*> parent;
    setParent(root, parent);
    Node* targetNode = findTarget(root, target);
    unordered_map<int, int> visited;

    return dfs(targetNode, visited, parent) - 1; 
}

int main() {
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //   4   5 6   7

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int target = 2;
    cout << minTime(root, target) << endl;

    return 0;
}