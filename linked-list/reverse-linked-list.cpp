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
void inserttail(node* &head,int val)
{
    node* n=new node(val);
    if(head==NULL)
    {
        head=n;
        return ;
    }
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
}
void print(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void reverse(node* &head)
{
    node* cur=head;
    node* prev=NULL;
    node* next=NULL;
    while(cur!=NULL)
    {
        next=cur->next;
        cur->next=prev;
        prev = cur;
        cur = next;
    }
    head=prev;
}
int main()
{
    node* head=NULL;
    inserttail(head,1);
    inserttail(head,2);
    inserttail(head,3);
    inserttail(head,4);
    print(head);
    reverse(head);
    print(head);
}