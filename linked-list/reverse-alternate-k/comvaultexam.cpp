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
node *reverse(node* head, int k)
{
    if (!head)
        return NULL;
    node *cur = head;
    node *next = NULL;
    node *prev = NULL;
    int count = 0;
    while (cur != NULL && count < k)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        count++;
    }
    if(head != NULL)
    head->next = cur;
    count = 0;
    while(count < k-1 && cur != NULL )
    {
    cur = cur->next;
    count++;
    }
    if(cur != NULL)
    cur->next = reverse(cur->next, k);
    head = prev;
}
int main()
{
    node *head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    insert(head, 7);
    insert(head, 8);
    insert(head, 9);
    disp(head);
    head = reverse(head, 3);
    disp(head);
    return 0;
}