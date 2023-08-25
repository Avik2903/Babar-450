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
void split(node* source,node** s,node** f);
node* sorty(node* a,node*b);
void mergesort(node** head)
{
    node* temp=*head;
    node* a;
    node* b;
    if(temp==NULL ||temp->next==NULL)
    return ;
    split(temp,&a,&b);
    mergesort(&a);
    mergesort(&b);
    *head=sorty(a,b);

}
node* sorty(node* a,node*b)
{
    node* res=NULL;
    if(a==NULL)
        return (b);
    if(b==NULL)
        return (a);
    if(a->data<=b->data)
    {
        res=a;
        res->next=sorty(a->next,b);
    }
    else
    {
        res=b;
        res->next=sorty(a,b->next);
    }
    return (res);
}
void split(node* source,node** front,node** back)
{
    node* s=source;
    node* f=source->next;
    while(f!=NULL)
    {
        f=f->next;
        if(f!=NULL)
        {
            s=s->next;
            f=f->next;
        }
    }
    *front=source;
    *back=s->next;
    s->next = NULL;
}
void push(node* &head,int val)
{
    node* n=new node(val);
    if(!head)
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
int main() {
    node* head=NULL;
    node* res=NULL;
    int arr[]={2,7,9,5,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
    {
        push(head,arr[i]);
    }
    mergesort(&head);

    print(head);
    return 0;
}