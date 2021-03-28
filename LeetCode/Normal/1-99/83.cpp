#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
            return head;
        ListNode *tail = head->next, *pre = head;
        while (tail)
        {
            if (pre->val == tail->val)
            {
                pre->next = tail->next;
            }
            else
            {
                pre = pre->next;
            }
            tail = tail->next;
        }
        return head;
    }
};