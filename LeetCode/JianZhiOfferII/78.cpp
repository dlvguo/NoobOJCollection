#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        // 最小堆
        auto cmp = [&](const ListNode *lhs, const ListNode *rhs)
        {
            return lhs->val > rhs->val;
        };
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> heap(cmp);

        ListNode *dummy = new ListNode();
        ListNode *cur = dummy;
        for (auto &node : lists)
        {
            if (node != nullptr)
            {
                heap.push(node);
            }
        }

        while (!heap.empty())
        {
            ListNode *node = heap.top();
            heap.pop();
            if (node->next != nullptr)
            {
                heap.push(node->next);
            }
            cur->next = node;
            cur = cur->next;
        }

        ListNode *ret = dummy->next;
        delete dummy;
        dummy = nullptr;

        return ret;
    }
};
