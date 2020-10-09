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
    bool hasCycle(ListNode *head)
    {
        if (!head)
            return false;
        ListNode *last = head;
        do
        {
            head = head->next;
            last = last->next;
            if (!last)
            {
                return false;
            }
            else
            {
                last = last->next;
            }
            if (head == last)
                return true;
        } while (head && last);
        return false;
    }
};