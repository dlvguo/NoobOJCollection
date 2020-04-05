#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseList(ListNode *head)
{
    if (!head)
        return head;
    ListNode *newHead = head,*p;
    head = head->next;
    newHead->next = NULL;
    while (head)
    {
        p=head;
        head=head->next;
        p->next=newHead;
        newHead=p;
    }
    return newHead;
}