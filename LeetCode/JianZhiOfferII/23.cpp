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
        ListNode *pa=headA,*pb=headB;
        while (pa!=pb)
        {
            pa=pa?pa->next:headB;
            pb=pb?pb->next:headA;
        }
        return pa;
        
    }
};