#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    struct node *next;
};

struct node *head = NULL;

void ins(int v)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    ptr->val = v;

    if (!head)
    {

        head = ptr;
        ptr->next = head;
    }
    else
    {

        struct node *temp = head;
        while (temp->next != head)

            temp = temp->next;

        temp->next = ptr;
        ptr->next = head;
    }
}

void print()
{

    struct node *temp = head;
    while (1)
    {
        cout << temp->val << "->";

        temp = temp->next;
        if (temp == head)
            break;
    }
}

int main()
{

    int n, i, k;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> k;
        ins(k);
    }
    print();
    return 0;
}