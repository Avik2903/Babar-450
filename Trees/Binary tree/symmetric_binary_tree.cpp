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

bool issymmetrichelp(Node* left, Node* right)
{
    if(left==NULL || right== NULL)
    {
        return left==right;
    }

    if(left->data!=right->data) return false;

    return issymmetrichelp(left->left,right->right) && issymmetrichelp(left->right,right->left);

}

bool issymmetric(Node* root)
{
    return root==NULL || issymmetrichelp(root->left,root-> right);
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    //cout << (issymmetric(root) ? "True": "False");
    cout<<boolalpha<<issymmetric(root);
    return 0;
}
