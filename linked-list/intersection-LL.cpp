#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node *next;
        node(int val)
        {
            data=val;
            next = NULL;
        }
};
void push(node* &head,int val)
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
void print(node* &head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
node* inter(node* a,node* b)
{
    if (a == NULL || b == NULL)
        return NULL;
    if (a->data < b->data)
        return inter(a->next, b);
    if (a->data > b->data)
        return inter(a, b->next);
    node* temp = (node*)malloc(sizeof(node));
    temp->data = a->data;
    temp->next = inter(a->next,b->next);
    return temp;
}
int main()
{
    node* a=NULL;
    node* b=NULL;
    node* intersect=NULL;

    push(a,1);
    push(a,5);
    push(a,3);
    push(a,6);
    push(a,5);

    push(b,3);
    push(b,2);
    push(b,4);
    intersect=inter(a,b);
    cout<<"The intersection of Both the Linked List are:"<<endl;
    print(intersect);
    return 0;
}