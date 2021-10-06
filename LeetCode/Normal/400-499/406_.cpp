#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    typedef struct LinkList
    {
        int k, h;
        LinkList *next;
        LinkList(int h1, int k1) : k(k1), h(h1), next(NULL)
        {
        }
    } * LL;

    bool static cmp(const vector<int> &a, const vector<int> &b)
    {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] > b[0];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> res;
        //设为头节点
        LL head = new LinkList(0, 0), tail = head, pre = NULL;
        for (int i = 0; i < people.size(); i++)
        {
            pre = head;
            int k = people[i][1];
            while (k--)
            {
                pre = pre->next;
            }
            LL temp = new LinkList(people[i][0], people[i][1]);
            temp->next = pre->next;
            pre->next = temp;
        }
        pre = head->next;
        while (pre)
        {
            res.push_back({pre->h, pre->k});
            pre = pre->next;
        }
        return res;
    }
};