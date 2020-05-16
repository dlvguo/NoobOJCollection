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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *p = head, *l = head;
        stack<int> s;

        while (l)
        {
            s.push(l->val);
            l = l->next;
            if (s.size() == k)
            {
                while (s.size())
                {
                    p->val = s.top();
                    s.pop();
                    p = p->next;
                }
            }
        }
        return head;
    }
};