#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *deleteNode(ListNode *head, int val)
    {
        ListNode *pre = NULL, *p = head;
        while (p && p->val != val)
        {
            pre = p;
            p = p->next;
        }
        if (!pre)
            return head->next;
        if (p)
            pre->next = p->next;
        return head;
    }
};