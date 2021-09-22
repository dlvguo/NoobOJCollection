#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//模拟
class Solution
{
public:
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        vector<ListNode *> vlst;
        int len = 0;
        ListNode *p = head, *temp, *pre = NULL;
        while (p)
        {
            len++;
            p = p->next;
        }
        int avg = len / k, remain = len % k;
        p = head;
        for (int i = 0; i < remain; i++)
        {
            vlst.push_back(p);
            //多1注意
            for (int j = 0; j < 1 + avg; j++)
            {
                pre = p;
                p = p->next;
            }
            pre->next = NULL;
        }
        for (int i = remain; i < k; i++)
        {
            vlst.push_back(p);
            for (int j = 0; j < avg; j++)
            {
                if (p)
                {
                    pre = p;
                    p = p->next;
                }
            }
            if (p)
                pre->next = NULL;
        }

        return vlst;
    }
};