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
void push(node* &head,int val)
{
    node* n = new node(val);
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
void middle(node* &head)
{
    node* t=head;
    node* s=t;
    node* f=t->next;
    while(f!=NULL)
    {
        f=f->next;
        if(f!=NULL)
        {
            f=f->next;
            s=s->next;
        }
    }
    cout<<"Middle Element is : "<<s->data;
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
int main()
{
    node* head=NULL;
    int arr[]={2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
    {
        push(head,arr[i]);
    }
    print(head);
    middle(head);
    return 0;
}