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

bool search(Node* root,int key)
{
    bool flag= false;
    while(root){
        if(root->data==key)
        {
            flag = true;
            break;
        }
        else if(key > root->data)
            root=root->right;
        else
            root=root->left;
    }
    return flag;

    // while(root && root->data!=key)
    // {
    //     root= key>root->data? root->right:root->left;
    // }
    // return root;
}


int main()
{
    Node* root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(8);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    int key = 2;
    
    //Searching for key in BST
    cout <<boolalpha <<search(root, key) << endl;
    return 0;
}