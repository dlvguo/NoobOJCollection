#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> arr;

public:
    Solution(ListNode *head)
    {
        while (head)
        {
            arr.emplace_back(head->val);
            head = head->next;
        }
    }

    int getRandom()
    {
        return arr[rand() % arr.size()];
    }
};
