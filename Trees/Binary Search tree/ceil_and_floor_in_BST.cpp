#include<bits/stdc++.h>
using namespace std;
class Node{
    public: 
    int data;
    Node* left,*right;
    Node(int val)
    {
        data=val;
        left=right=nullptr;
    }
};

int findceil(Node* root, int key)
{
    int ans=-1;
    while(root)
    {
        if(root->data == key)
            return root->data;

        if(key>root->data)
            root=root->right;
        else
        {
            ans=root->data;
            root=root->left;
        }
    }
    return ans;
}

int findfloor(Node* root, int key)
{
    int ans=-1;
    while(root)
    {
        if(root->data == key)
            return root->data;

        if(key>root->data)
        {
            ans=root->data;
            root=root->right;
        }
        else
            root=root->left;
    }
    return ans;
}

int main()
{
    Node* root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(8);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    int key = 5;
    
    // Searching for key in BST
    cout << findceil(root, key) << endl;
    cout << findfloor(root, key) << endl;
    return 0;
}