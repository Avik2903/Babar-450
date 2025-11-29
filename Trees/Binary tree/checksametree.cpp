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

bool isIdentical(Node* r1, Node* r2)
{
    if(!r1 && !r2)  // If both trees are empty, they are identical
        return true;
    if(!r1 || !r2)  // If only one tree is empty, they are not identical
        return false;

    return (r1->data == r2->data) && isIdentical(r1->left,r2->left) && isIdentical(r1->right,r2->right);
}

int main()
{
      Node* r1 = new Node(1);    
    r1->left = new Node(2);   
    r1->right = new Node(3); 
    r1->left->left = new Node(4); 
    Node* r2 = new Node(1);    
    r2->left = new Node(2);   
    r2->right = new Node(3);  
    r2->left->left = new Node(5);

    if (isIdentical(r1, r2))
        cout << "true\n";
    else
        cout << "false\n";
    return 0;
}