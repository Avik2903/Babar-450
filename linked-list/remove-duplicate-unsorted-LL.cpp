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
// higher time complexity O(nlogn)
/*void remove(node* &head)
{
    node* temp=head;
    node* a=NULL;
    while(temp!=NULL)
    {
        a=temp->next;
        while(a!=NULL)
        {
            if(temp->data==a->data)
            {
                temp->next=a->next;
                free(a);
                a=temp->next;
            }
            else
            {
                a=a->next;
            }
        }
        temp=temp->next;
    }
}*/
//less time complexity O(N)
void remove(node* head)  
{
    unordered_set<int> s;
    node* temp = head;
    node* a=NULL;
    while (temp!=NULL) {
        if(s.find(temp->data)!=s.end())
        {
            a->next=temp->next;
            delete(temp);
        }
        else
        {
            s.insert(temp->data);
            a=temp;
        }
        temp=a->next;
    }
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
    insert(head, 1);
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    dis(head);
    remove(head);
    dis(head);
    return 0;
}