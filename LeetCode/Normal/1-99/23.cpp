#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *merge(ListNode *l1, ListNode *l2)
{

    if (!l1)
        return l2;
    if (!l2)
        return l1;
    ListNode *head, *r;
    if (l1->val > l2->val)
    {
        head = l2;
        l2 = l2->next;
    }
    else
    {
        head = l1;
        l1 = l1->next;
    }
    r = head;
    while (l1 && l2)
    {
        if (l1->val > l2->val)
        {
            r->next = l2;
            l2 = l2->next;
        }
        else
        {
            r->next = l1;
            l1 = l1->next;
        }
        r = r->next;
    }
    r->next = l1 ? l1 : l2;
    return head;
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    int step = 2, count = 1,len=lists.size();
    while ((step/2) <= len)
    {
        for (int i = 0; i < len; i += step)
        {
            if((i+count)<len){
                lists[i]=merge(lists[i],lists[i+count]);
            }
        }
        count*=2;
        step*=2;
    }
    return lists.size() == 0 ? NULL : lists[0];
}

int main()
{
    vector<ListNode *> a;
    ListNode *head = new ListNode(1);
    ListNode *n = new ListNode(4);
    head->next = n;
    a.push_back(head);
    head = new ListNode(5);
    n->next = head;
    head = new ListNode(1);
    a.push_back(head);
    n = new ListNode(3);
    head->next = n;
    head = new ListNode(4);
    n->next = head;
    head = new ListNode(2);
    a.push_back(head);
    n = new ListNode(6);
    head = mergeKLists(a);
    while (head)
    {
        cout << head->val;
        head = head->next;
    }
}

// 14.19%版本
/*
class Solution {
public:
    ListNode *merge(struct ListNode *l1, ListNode *l2)
{

    if (!l1)
        return l2;
    if (!l2)
        return l1;
    ListNode *head, *r;
    if (l1->val > l2->val)
    {
        head = l2;
        l2 = l2->next;
    }
    else
    {
        head = l1;
        l1 = l1->next;
    }
    r = head;
    while (l1 && l2)
    {
        if (l1->val > l2->val)
        {
            r->next = l2;
            l2 = l2->next;
        }
        else
        {
            r->next = l1;
            l1 = l1->next;
        }
        r = r->next;
    }
    r->next=l1?l1:l2;
    return head;
}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
          ListNode *temp;
    while (lists.size()>1)
    {
        temp=merge(lists[0],lists[1]);
        lists.erase(lists.begin());
                lists.erase(lists.begin());

        lists.push_back(temp);
    }
    return lists.size()==0?NULL: lists[0];
    }
};
*/