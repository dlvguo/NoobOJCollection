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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        stack<int> num1, num2;
        ListNode *lp = l1;
        ListNode *head = NULL, *p;

        while (lp)
        {
            num1.push(lp->val);
            lp = lp->next;
        }
        lp = l2;
        while (lp)
        {
            num2.push(lp->val);
            lp = lp->next;
        }
        int dig = 0, i1, i2;
        while (num1.size() && num2.size())
        {
            dig = num1.top() + num2.top() + dig;
            num1.pop();
            num2.pop();
            p = new ListNode(dig % 10);
            p->next = head;
            head = p;
            dig /= 10;
        }

        if (num1.size())
        {
            while (num1.size())
            {
                dig = num1.top() + dig;
                num1.pop();
                p = new ListNode(dig % 10);
                p->next = head;
                head = p;
                dig /= 10;
            }
        }
        else if (num2.size())
        {
            while (num2.size())
            {
                dig = num2.top() + dig;
                num2.pop();
                p = new ListNode(dig % 10);
                p->next = head;
                head = p;
                dig /= 10;
            }
        }

        if (dig)
        {
            p = new ListNode(1);
            p->next = head;
            head = p;
        }
        return head;
    }
};