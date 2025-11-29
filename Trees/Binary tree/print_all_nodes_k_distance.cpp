// C++ program to find nodes
// at distance k from target.
#include <bits/stdc++.h>
using namespace std;

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

// Function which maps the nodes to its parent nodes
// and returns the target node.
Node *findTarNode(Node *root, int target, unordered_map<Node*, Node*> &parent) {

    Node *left = nullptr, *right = nullptr;
    
    // map the left child to root node 
    // and search for target node in 
    // left subtree.
    if (root->left != nullptr) {
        parent[root->left] = root;
        left = findTarNode(root->left, target, parent);
    }
    
    // map the right child to root node and search 
    // for target node in right subtree.
    if (root->right != nullptr) {
        parent[root->right] = root;
        right = findTarNode(root->right, target, parent);
    }
    
    // If root node is target, then
    // return root node.
    if (root->data == target) {
        return root;
    }
    
    // If target node in found in left
    // subtree, then return left.
    else if (left != nullptr) {
        return left;
    }
    
    // return the result from
    // right subtree.
    return right;
}

// depth first function to find nodes k 
// distance away.
void dfs(Node *root, Node *prev, int k, 
         unordered_map<Node *, Node *> &parent, vector<int> &ans) {

    // base case
    if (root == nullptr)
        return;
    
    // If current node is kth 
    // distance away.
    if (k == 0) {
        ans.push_back(root->data);
        return;
    }

    if (root->left != prev)
        dfs(root->left, root, k - 1, parent, ans);

    if (root->right != prev)
        dfs(root->right, root, k - 1, parent, ans);

    if (parent[root] != prev)
        dfs(parent[root], root, k - 1, parent, ans);
}

vector<int> KDistanceNodes(Node *root, int target, int k) {
    vector<int> ans;

    if (root == nullptr)
        return ans;
    
    // find the target nodes and map the nodes
    // to their parent nodes.
    unordered_map<Node *, Node *> parent;
    Node *tar = findTarNode(root, target, parent);

    dfs(tar, nullptr, k, parent, ans);

    // sort the result
    sort(ans.begin(), ans.end());

    return ans;
}

void printList(vector<int> v) {
    int n = v.size();
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {

    // Create a hard coded tree.
    //         20
    //       /    \
    //      7      24
    //    /   \
    //   4     3
    //        /
    //       1
    Node *root = new Node(20);
    root->left = new Node(7);
    root->right = new Node(24);
    root->left->left = new Node(4);
    root->left->right = new Node(3);
    root->left->right->left = new Node(1);

    int target = 7, k = 2;
    vector<int> ans = KDistanceNodes(root, target, k);

    printList(ans);
    return 0;
}