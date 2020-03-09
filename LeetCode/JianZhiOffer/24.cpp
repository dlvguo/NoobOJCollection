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
    ListNode *reverseList(ListNode *head)
    {
        if(!head)
            return NULL;
        ListNode *p=head->next,*temp;
        head->next=NULL;
        while (p)
        {
            temp=p;
            p=p->next;
            temp->next=head;
            head=temp;
        }
        return head;
    }
};