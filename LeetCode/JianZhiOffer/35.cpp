#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return head;
        Node *tail = head;
        //链表节点复制
        while (tail)
        {
            Node *copy = new Node(tail->val);
            copy->next = tail->next;
            tail->next = copy;
            tail = copy->next;
        }
        tail = head;
        //随机节点复制
        while (tail)
        {
            if (tail->random)
            {
                tail->next->random = tail->random->next;
            }
            tail = tail->next->next;
        }
        tail = head;
        //链表一分为二
        Node *newhead = head->next;
        Node *tmp = NULL;
        while (tail->next)
        {
            tmp = tail->next;
            tail->next = tail->next->next;
            tail = tmp;
        }
        return newhead;
    }
};