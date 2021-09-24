#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution
{
public:
    void f(Node *head)
    {

        while (head)
        {
            //递归孩子
            if (head->child)
            {
                f(head->child);
                Node *temp = head->next;
                head->next = head->child;
                head->next->prev = head;
                head->child = NULL;
                while (head->next)
                {
                    head = head->next;
                }
                head->next = temp;
                if (temp)
                    temp->prev = head;
            }
            head = head->next;
        }
    }

    Node *flatten(Node *head)
    {
        if (head)
            f(head);
        return head;
    }
};