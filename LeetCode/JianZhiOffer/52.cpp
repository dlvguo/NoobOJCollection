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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        stack<ListNode *> stack1, stack2;
        while (headA && headB)
        {
            stack1.push(headA);
            stack2.push(headB);
            headA = headA->next;
            headB = headB->next;
        }
        while (headA)
        {
            stack1.push(headA);
            headA = headA->next;
        }
        while (headB)
        {
            stack2.push(headB);
            headB = headB->next;
        }
        ListNode *pre = NULL;
        while (!stack1.empty()&&!stack2.empty()&&stack1.top() == stack2.top())
        {
            pre = stack1.top();
            stack1.pop();
            stack2.pop();
        }
        return pre;
    }
};