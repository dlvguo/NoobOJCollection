#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//常规用栈解法
// class Solution
// {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
//     {
//         stack<ListNode *> as, bs;
//         ListNode *head = headA;
//         while (head)
//         {
//             as.push(head);
//             head = head->next;
//         }
//         head = headB;
//         while (head)
//         {
//             bs.push(head);
//             head = head->next;
//         }
//         head = NULL;
//         while (!as.empty() && !bs.empty() && as.top() == bs.top())
//         {
//             head = as.top();
//             as.pop();
//             bs.pop();
//         }
//         return head;
//     }
// };

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *head = headA;
        int alen = 0, blen = 0;
        while (head)
        {
            alen++;
            head = head->next;
        }
        head = headB;
        while (head)
        {
            blen++;
            head = head->next;
        }
        head = NULL;
        while (alen < blen)
        {
            headB = headB->next;
            blen--;
        }
        while (blen < alen)
        {
            headA = headA->next;
            alen--;
        }
        while (alen)
        {
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
            alen--;
        }

        return NULL;
    }
};