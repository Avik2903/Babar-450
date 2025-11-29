#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

vector<int> zigZagTraversal(Node* root) {
    vector<int> res;
    if (!root) return res;

    deque<Node*> dq;
    dq.push_back(root);

    bool reverse = false;

    while (!dq.empty()) {
        int n = dq.size();

        while (n--) {
            
            // Push right to the front 
            // first if reverse is true
            if (reverse) {
                Node* curr = dq.back();
                dq.pop_back();
                res.push_back(curr->data);

                if (curr->right) dq.push_front(curr->right);
                if (curr->left)  dq.push_front(curr->left);
            }
            
            // Else push left to the back first
            else {
                Node* curr = dq.front();
                dq.pop_front();
                res.push_back(curr->data);

                if (curr->left)  dq.push_back(curr->left);
                if (curr->right) dq.push_back(curr->right);
            }
        }

        reverse = !reverse;
    }

    return res;
}

int main() {

    // Create a input binary tree
    //         20
    //       /   \
    //      8     22
    //    /  \     \
    //   4   12    11
    //      /  \
    //     10   14
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->right->right = new Node(11);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    
    vector<int> res = zigZagTraversal(root);
    for (auto val: res) cout << val << " ";
    cout << endl;

    return 0;
}