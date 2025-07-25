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

int find_max(Node *head)
{
    if (head == NULL)
        return INT_MIN; 

    int maximum = head->val;
    while (head != NULL)
    {
        if (head->val > maximum)
        {
            maximum = head->val;
        }
        head = head->next;
    }
    return maximum;
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

    cout << find_max(head) << endl;

    return 0;
}
