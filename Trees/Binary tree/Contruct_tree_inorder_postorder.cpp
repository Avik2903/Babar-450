#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data= val;
        left=right=nullptr;
    }
};



Node* Abuilttree(vector<int> in, int is,int ie, vector<int> post,int ps,int pe, map<int,int> &mp)
{
    if(ps>pe || is>ie)
    {
        return NULL;
    }

    Node* root = new Node(post[pe]);
    int inroot=mp[root->data];
    int numsleft=inroot-is;

    root->left = Abuilttree(in,is,inroot-1,post,ps,ps+numsleft-1,mp);
    root->right = Abuilttree(in,is+inroot+1,ie,post,ps+numsleft,pe-1,mp);

    return root;
}

Node* buildTree(vector<int>& post, vector<int>& in)
{

    if(post.size()!=in.size())
        return NULL;

    map<int,int> map;

    for(int i=0;i<in.size();i++)
    {
        map[in[i]]=i;
    }

    Node* root= Abuilttree(in,0,in.size()-1,post,0,post.size()-1,map);
    return root;
}

void printVector(vector<int>& arr)
{
    for(int i =0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void printpreorder(Node* root){
    if(!root){
        return;
    }
    cout << root->data << " ";
    printpreorder(root->left);
    printpreorder(root->right);
}

int main()
{
    vector<int> inorder = {40, 20 , 50, 10, 60, 30};
    vector<int> postorder = {40, 50, 20, 60, 30, 10};
    
    cout << "Inorder Vector: ";
    printVector(inorder);
    
    cout << "Postorder Vector: ";
    printVector(postorder);
    

    Node* root = buildTree(postorder, inorder);
    
    cout << "Preorder of Unique Binary Tree Created: "<< endl;
    printpreorder(root);
    cout << endl;

    return 0;
}