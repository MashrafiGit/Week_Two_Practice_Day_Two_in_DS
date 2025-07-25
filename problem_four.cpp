#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

int list_size(Node *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}

bool insert_at_index(Node *&head, Node *&tail, int index, int val)
{
    int sz = list_size(head);
    if (index < 0 || index > sz)
        return false; 

    Node *newNode = new Node(val);

    if (index == 0)
    {
        newNode->next = head;
        head = newNode;
        if (tail == NULL)
            tail = newNode;
        return true;
    }

    Node *temp = head;
    for (int i = 0; i < index - 1; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    if (newNode->next == NULL)
        tail = newNode;

    return true;
}

void print_list(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int x;
    while (cin >> x && x != -1)
    {
        insert_at_tail(head, tail, x);
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int idx, val;
        cin >> idx >> val;

        bool inserted = insert_at_index(head, tail, idx, val);
        if (!inserted)
        {
            cout << "Invalid" << endl;
        }
        else
        {
            print_list(head);
        }
    }

    return 0;
}
