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

void print_list(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void sort_descending(Node *head)
{
    vector<int> v;
    Node *temp = head;
    while (temp != NULL)
    {
        v.push_back(temp->val);
        temp = temp->next;
    }

    sort(v.begin(), v.end(), greater<int>());

    temp = head;
    int i = 0;
    while (temp != NULL)
    {
        temp->val = v[i++];
        temp = temp->next;
    }
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

    sort_descending(head);
    print_list(head);

    return 0;
}
