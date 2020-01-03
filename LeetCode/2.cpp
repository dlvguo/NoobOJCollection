#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    int carry = 0;
    ListNode *head = NULL;
    ListNode *p ;
    while (l1 && l2)
    {
        int temp = l1->val + l2->val + carry;
        carry = temp / 10;
        temp %= 10;
        ListNode *node = new ListNode(temp);
        node->next=NULL;
        if (!head) //说明头节点
        {
            head=node;
            p=node;
        }
        else
        {
            p->next=node;
            p=node;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1)
    {
        int temp = l1->val + carry;
        carry = temp / 10;
        temp %= 10;
        ListNode *node = new ListNode(temp);
        node->next = NULL;
        p->next = node;
        p = node;
        l1 = l1->next;
    }
    while (l2)
    {
        int temp = l2->val + carry;
        carry = temp / 10;
        temp %= 10;
        ListNode *node = new ListNode(temp);
        node->next = NULL;
        p->next = node;
        p = node;
        l2 = l2->next;
    }
    if (carry)
    {
        ListNode *node = new ListNode(1);
        node->next = NULL;
        p->next = node;
    }
    return head;
}
int main()
{
}