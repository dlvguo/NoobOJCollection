#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


vector<int> reversePrint(ListNode *head)
{
    vector<int> v;
    int count=0;
    ListNode *p=head;
    while (head)
    {
        count++;
        head=head->next;
    }
    v.resize(count);
    while (p)
    {
        v[--count]=p->val;
        p=p->next;
    }

    return v;
}