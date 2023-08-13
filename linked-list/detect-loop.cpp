#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
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
// bool detectloop(node* head)
// {
//     unordered_set<node*> m;
//     while(head!=NULL)
//     {
//         if(m.find(head)!=m.end())
//         {
//             return true;
//         }
//         m.insert(head);
//         head=head->next;
//     }
// return false;
// }

/* Floyd Cycle detection technique*/
bool detectloop(node* head)
{
    node* f=head;
    node* s=head;
    while(f && s && f->next)
    {
        s=s->next;
        f=f->next->next;
        if(s==f)
        {
            return true;
        }
    }
return false;
}

void disp(node* head)
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
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    head->next->next->next->next=head;
    //disp(head);
    if(detectloop(head)==true)
    cout<<"loop detected";
    else
    cout<<"No loop detected";
    return 0;
} 

