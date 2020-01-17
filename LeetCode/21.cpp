#include <iostream>
#include <bits/stdc++.h>
#include <cstring>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    struct ListNode *head = NULL, *p, *temp;
    if (l1->val > l2->val)
    {
        head = l2;
        p = head;
        l2 = l2->next;
    }
    else
    {
        head = l1;
        p = head;
        l1 = l1->next;
    }
    while (l1 && l2)
    {

        if (l1->val > l2->val)
        {
            temp = l2;
            l2 = l2->next;
        }
        else
        {
            temp = l1;
            l1 = l1->next;
        }
        p->next = temp;
        p = p->next;
    }
    p->next = l1 ? l1 : l2;
    return head;
}

int main()
{
}