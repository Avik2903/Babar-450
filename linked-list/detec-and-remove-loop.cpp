#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
void insert(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
bool detectloop(node *head)
{
    node *s = head;
    node *f = head;
    while (s && f && f->next)
    {
        s = s->next;
        f = f->next->next;
        if (s == f)
            return true;
    }
    return false;
}
void removeloop(node *head)
{
    if (head == NULL && head->next == NULL)
    {
        return head;
    }
    Node *s = head;
    Node *f = head;
    while (f && f->next)
    {
        s = s->next;
        f = f->next->next;
        if (s == f)
        {
            break;
        }
    }
    if (s == f)
    {
        s = head;
        if (s == f)
        {
            while (f->next != s)
            {
                f = f->next;
            }
        }
        else
        {
            while (f->next != s->next)
            {
                s = s->next;
                f = f->next;
            }
        }
        f->next = NULL;
    }
}
void disp(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    node *head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    head->next->next->next->next = head;
    if (detectloop(head))
        cout << "Loop detected" << endl;
    else
        cout << "No loop detected" << endl;
    removeloop(head);
    disp(head);
    return 0;
}