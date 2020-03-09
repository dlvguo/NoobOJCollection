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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        ListNode *head, *rear;
        if (l1->val > l2->val)
        {
            head = rear = l2;
            l2 = l2->next;
        }
        else
        {
            head = rear = l1;
            l1 = l1->next;
        }
        while (l1 && l2)
        {
            if (l1->val > l2->val)
            {
                rear->next = l2;
                l2 = l2->next;
                rear = rear->next;
            }
            else
            {
                rear->next = l1;
                l1 = l1->next;
                rear = rear->next;
            }
        }
        rear->next = l1 ? l1 : l2;
        return head;
    }
};