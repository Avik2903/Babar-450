// #include<bits/stdc++.h>  // O(n)  O(n)  brute force
// using namespace std;
// class Node{
//     public:
//     int data;
//     Node* left,*right;
//     Node(int val)
//     {
//         data=val;
//         left=right=nullptr;
//     }
// };
// Node* prevNode = NULL;
// // Flattens the binary tree to a linked list in-place using reverse postorder traversal (right, left, root).
// // After flattening, the left child of all nodes should be NULL and the right child forms the linked list.
// void flatten(Node* root)
// {
//     if(!root)
//         return;

//     flatten(root->right);
//     flatten(root->left);

//     root->right=prevNode;
//     root->left=NULL;
//     prevNode=root;
// }

// void PrintLL(Node* root)
// {
//     if(!root)
//         return;

//     cout<<root->data<<" ";
//     PrintLL(root->right);
// }

// int main(){
//     Node* root= new Node(1);
//     root->left=new Node(2);
//     root->right=new Node(5);
//     root->left->left=new Node(3);
//     root->left->right=new Node(4);
//     root->right->right=new Node(6);
//     root->right->right->left= new Node(7);
//     flatten(root);
//     PrintLL(root);

//     return 0;
// }

// #include<bits/stdc++.h>  //O(n) O(log n)  better approach
// using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

// class Solution {
// public:
//     // Initialize a global variable
//     // 'prev' to keep track of the
//     // previously processed node.
//     TreeNode* prev = NULL;

//     // Function to flatten a binary tree
//     // to a right next Linked List structure
//     void flatten(TreeNode* root) {
//         // Base case: If the current
//         // node is NULL, return.
//         if(root == NULL){
//             return;
//         }
//         // Use a stack for
//         // iterative traversal.
//         stack<TreeNode*> st;
//         // Push the root node
//         // onto the stack.
//         st.push(root);  
        
//         // Continue the loop until
//         // the stack is empty.
//         while (!st.empty()) {  
//             // Get the top node from the stack.
//             TreeNode* cur = st.top(); 
//             // Pop the top node.
//             st.pop();  

//             if (cur->right != NULL) {
//                  // Push the right child
//                  // onto the stack.
//                 st.push(cur->right); 
//             }
            
//             if (cur->left != NULL) {
//                  // Push the left child
//                  // onto the stack.
//                 st.push(cur->left); 
//             }

//             if (!st.empty()) {
//                 // Connect the right child to
//                 // the next node in the stack.
//                 cur->right = st.top();  
//             }
            
//             // Set the left child to NULL to
//             // form a right-oriented linked list.
//             cur->left = NULL;  
//         }
//     }
// };
// // Print the preorder traversal of the
// // Orignal Binary Tree
// void printPreorder(TreeNode* root){
//     if(!root){
//         return;
//     }
//     cout << root->val << " ";
//     printPreorder(root->left);
//     printPreorder(root->right);
// }

// // Print the Binary Tree along the 
// // Right Pointers after Flattening
// void printFlattenTree(TreeNode* root){
//     if(!root){
//         return;
//     }
//     cout << root->val << " ";
//     printFlattenTree(root->right);
// }


// int main() {

//     TreeNode* root = new TreeNode(1);
//     root->left = new TreeNode(2);
//     root->right = new TreeNode(3);
//     root->left->left = new TreeNode(4);
//     root->left->right = new TreeNode(5);
//     root->left->right->right = new TreeNode(6);
//     root->right->right = new TreeNode(7);
//     root->right->left = new TreeNode(8);

//     Solution sol;
    
//     cout << "Binary Tree Preorder: ";
//     printPreorder(root);
//     cout << endl;
    
//     sol.flatten(root);
    
//     cout << "Binary Tree After Flatten: ";
//     printFlattenTree(root);
//     cout << endl;
//     return 0;
// }

#include<bits/stdc++.h> // best approach O(2n) O(1)
using namespace std;

// TreeNode structure
class Node {
    public:
    int val;
    Node *left, *right;
    Node(int data)
    {
        val=data;
        left=right=nullptr;
    }
};

void flatten(Node* root) {
    while (root) {
        // if root->left is not NULL
        if (root->left != NULL) {
            // set curr node as root->left;
            Node* curr = root->left;
            // traverse to the extreme right of curr
            while (curr->right) {
                curr = curr->right;
            }
            // join curr->right to root->right
            curr->right = root->right;
            // put root->left to root->right
            root->right = root->left;
            // make root->left as NULL
            root->left = NULL;
        }
        // now go to the right of the root
        root = root->right;
    }
}



// Print the preorder traversal of the
// Orignal Binary Tree
void printPreorder(Node* root){
    if(!root){
        return;
    }
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

// Print the Binary Tree along the 
// Right Pointers after Flattening
void printFlattenTree(Node* root){
    if(!root){
        return;
    }
    cout << root->val << " ";
    printFlattenTree(root->right);
}


int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->right->right = new Node(7);
    root->right->left = new Node(8);
    
    cout << "Binary Tree Preorder: ";
    printPreorder(root);
    cout << endl;
    
    flatten(root);
    
    cout << "Binary Tree After Flatten: ";
    printFlattenTree(root);
    cout << endl;
    

    return 0;
}