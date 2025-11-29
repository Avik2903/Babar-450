#include<bits/stdc++.h>
using namespace std; 
class node{
    public:
    int data;
    node* next;

    node(int val)
    {
        data=val;
        next=NULL;
    }
};
void inserthead(node* &head,int val)
{
    node* n=new node(val);
    n->next=head;
    head=n;
}
void inserttail(node* &head,int val)
{
    node* n=new node(val);
    if(head==NULL)
    {
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
}
bool search(node* &head,int key)
{
    node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            return true;
        }
        temp=temp->next;
    }
    return false;
}
void print(node *head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
int main(){
node* head=NULL;
inserttail(head,1);
inserttail(head,2);
inserttail(head,3);
inserthead(head,5);
print(head);
cout<<search(head,3);
return 0;
}