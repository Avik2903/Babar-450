#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int val)
    {
        data=val;
        next=NULL;
        prev=NULL;
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
    n->prev=temp;
}
void sum(node* &head,int sum)
{
    node* first=head;
    node* second=head;
    while(second->next!=NULL)
    {
        second=second->next;
    }
    int a=0;
    while(first!=second and second->next!=first)
    {
        if((first->data)+(second->data)==sum)
        {
            a=1;
            cout<<"("<<first->data<<","<<second->data<<")"<<endl;
            first=first->next;
            second=second->prev;
        }
        else
        {
            if((first->data)+(second->data)<sum)
            {
                first=first->next;
            }
            else
            {
                second=second->prev;
            }
        }
    }
    if(a==0)
    {
        cout<<"No pair found";
    }
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
    sum(head,7);
    return 0;
}