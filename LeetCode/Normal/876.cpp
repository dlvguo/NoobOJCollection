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
    ListNode *middleNode(ListNode *head)
    {
        if (!head->next || !head)
            return head;
        ListNode *mid = head, *last = head->next;
        while (last)
        {
            mid = mid->next;
            last = last->next;
            if (last)
                last = last->next;
        }
        return mid;
    }
};