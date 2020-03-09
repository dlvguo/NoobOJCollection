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
    ListNode *getKthFromEnd(ListNode *head, int k)
    {
        ListNode *p = head;
        int count = 0;
        while (p)
        {
            count++;
            if (count == k)
                break;
            p = p->next;
        }
        if (!p)
            return NULL;
        while (p->next)
        {
            p = p->next;
            head = head->next;
        }
        return head;
    }
};