#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    ListNode *p = head, *last = head, *pre = NULL;
    int count = 0;

    while (p)
    {
        count++;
        if (count > n)
        {
            pre=last;
            last = last->next;
        }
        p = p->next;
    }
    if (pre)
    {
        pre->next = last->next;
    }
    else
        head = head->next;
    free(last);
    return head;
}

int main()
{
}