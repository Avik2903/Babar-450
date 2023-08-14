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
void remove(node* head)
{
    node* temp=head;
    node* a;
    if(temp==NULL)
    return;
    while(temp->next!=NULL)
    {
        if(temp->data==temp->next->data)
        {
            a=temp->next->next;
            delete(temp->next);  //can use free(temp->next) also
            temp->next=a;
        }
        else
        {
            temp=temp->next;
        }
    }
}
/* uses map but doesn't change the linked-list just prints the answer*/
/*void remove(node* head)  
{
    unordered_map<int, bool> track;
    node* temp = head;
    while (temp) {
        if (track.find(temp->data) == track.end()) {
            cout << temp->data << " ";
        }
        track[temp->data] = true;
        temp = temp->next;
    }
}*/
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