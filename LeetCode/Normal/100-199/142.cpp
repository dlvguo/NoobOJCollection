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
    ListNode *detectCycle(ListNode *head)
    {
        unordered_set<ListNode *> visited;
        while (head)
        {
            if (visited.count(head))
            {
                return head;
            }
            visited.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};