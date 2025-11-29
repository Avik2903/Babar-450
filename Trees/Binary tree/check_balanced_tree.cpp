/*#include<bits/stdc++.h>  // O(n^2) and O(h)
using namespace std;
class Node{
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

int depth(Node* node)
{
    if(node== NULL)
    return 0;

    int lh= depth(node->left);
    int rh= depth(node->right);
    return 1+max(lh,rh);
}

bool checkBt(Node* root)
{
    if(root == NULL)
        return true;

    int lH = depth(root->left);
    int rH = depth(root->right);

    if(abs(lH-rH)>1)
        return false;

    return checkBt(root->left) && checkBt(root->right);
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout<<(checkBt(root) ? "True" : "False");

    return 0;
}*/


#include<bits/stdc++.h>   //// O(n) and O(h)
using namespace std;
class Node{
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

int isbalanced(Node* node)
{
    if(node== NULL)
    return 0;

    int lh= isbalanced(node->left);
    int rh= isbalanced(node->right);

    if(lh == -1 || rh == -1 || abs(lh-rh)>1)
        return -1;
    return 1+max(lh,rh);
}


int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout<<(isbalanced(root)>0 ? "True" : "False");

    return 0;
}