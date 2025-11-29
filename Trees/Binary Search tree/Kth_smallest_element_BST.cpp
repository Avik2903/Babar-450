#include <iostream>
using namespace std;

// Node Structure
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

// Function to find kth Smallest
int kthSmallest(Node *root, int k)
{
    int count = 0;

    Node *curr = root;
    while (curr != nullptr)
    {
        if (curr->left == nullptr)
        {
            count++;
            if (count == k)
                return curr->data;
            curr = curr->right;
        }
        else
        {
            // Find the inorder predecessor of curr
            Node *prev = curr->left;
            while (prev->right != nullptr && prev->right != curr)
            {
                prev = prev->right;
            }

            // Make curr the right child of its inorder predecessor
            if (prev->right == nullptr)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                count++;
                if (count == k)
                    return curr->data;

                // Revert the changes made in the tree structure
                prev->right = nullptr;
                curr = curr->right;
            }
        }
    }
    return -1;
}

int main()
{
    // Binary search tree
    //      20
    //    /   \
    //   8     22
    //  / \
    // 4   12
    //    /  \
    //   10   14
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    int k = 3;

    cout << kthSmallest(root, k) << endl;
}
