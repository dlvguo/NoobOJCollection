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
    ListNode *detectCycle(ListNode *head)
    {
        if (!head)
            return head;
        ListNode *h = head, *n = head;
        while (n->next && n->next->next)
        {
            h = h->next;
            n = n->next->next;
            if (h == n)
                break;
            /* code */
        }

        if (n->next == NULL || n->next->next == NULL)
            return NULL;
        h = head;
        while (h != n)
        {
            h = h->next;
            n = n->next;
            /* code */
        }
        return h;
    }
};