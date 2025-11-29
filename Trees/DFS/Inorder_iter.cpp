#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data = val;
        left=right=nullptr;
    }
};

vector<int> Inorder(Node* root) 
{
    stack<Node*> s;
    Node* node = root;
    vector<int> res;
    while(true)
    {
        if(node != NULL)
        {
            s.push(node);
            node=node->left;
        }
        else
        {
            if(s.empty() == true)
                break;
            // get the node from top of stack, then pop it
            node = s.top();
            s.pop();
            res.push_back(node->data);
            node = node->right;
        }
    }
    return res;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> inorder = Inorder(root);

    for (int val : inorder) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
