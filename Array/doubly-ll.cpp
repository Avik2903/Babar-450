#include <iostream>

using namespace std;

struct node
{
    int val;
    struct node *next;
    struct node *prev;
};

// (datatype) malloc(sizeof())
struct node *head = NULL;

void LL(int t)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->val = t;
    ptr->next = NULL;

    if (head == NULL)
    {
        head = ptr;
        ptr->prev = NULL;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->prev = temp;
    }
}

void print()
{
    struct node *temp = head;
    while (temp->next != NULL)
    {
        // cout<<temp->val;
        temp = temp->next;
    }
    while (temp != NULL)
    {
        cout << temp->val;
        temp = temp->prev;
    }
    // reversing a linked list
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int g;
        cout << "enter value" << i << endl;
        cin >> g;
        LL(g);
    }
    print();
    return 0;
}

// int *ptr;