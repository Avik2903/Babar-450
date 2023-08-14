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
void insert(node* &head,int val)
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
node* detect(node* head)
{
    unordered_set<node*> map;
    node* temp=head;
    while(temp!=NULL)
    {
        if(map.find(temp)!=map.end())
        {
            return temp;
        }
        else{
            map.insert(temp);
        }
        temp=temp->next;
    }
    return NULL;
}
void dis(node* head)
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
    node *head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    //head->next->next->next->next = head;
    head->next->next->next->next->next = head->next->next;
    node* res=detect(head);
    if(res==NULL)
    {
        cout<<"Loop does not exist";
    }
    else
    {
        cout<<"Loop starting is: "<<res->data;
    }
    return 0;
}