#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    struct node
    {
        int n1, n2, val, x1, x2;
        node(int _n1, int _n2, int _val, int _x1, int _x2) : n1(_n1), n2(_n2), val(_val), x1(_x1), x2(_x2) {}
        bool operator<(const node &node2) const
        {
            return val > node2.val;
        }
    };

    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        priority_queue<node> pq;
        vector<vector<int>> res;
        unordered_set<string> _set;
        int l = 0, r = 0;
        node tn(0, 0, nums1[0] + nums2[0], nums1[0], nums2[0]);
        _set.insert(to_string(0) + "_" + to_string(0));
        pq.push(tn);
        while (pq.size() && k--)
        {
            node t = pq.top();
            pq.pop();
            res.push_back({t.x1, t.x2});
            if (t.n1 + 1 < nums1.size())
            {
                string s = to_string(t.n1 + 1) + "_" + to_string(t.n2);
                if (_set.find(s) == _set.end())
                {
                    node n(t.n1 + 1, t.n2, nums1[t.n1 + 1] + nums2[t.n2], nums1[t.n1 + 1], nums2[t.n2]);
                    pq.push(n);
                    _set.insert(s);
                }
            }
            if (t.n2 + 1 < nums2.size())
            {
                string s = to_string(t.n1) + "_" + to_string(t.n2 + 1);
                if (_set.find(s) == _set.end())
                {
                    node n(t.n1, t.n2 + 1, nums1[t.n1] + nums2[t.n2 + 1], nums1[t.n1], nums2[t.n2 + 1]);

                    pq.push(n);
                    _set.insert(s);
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<int> n1 = {1, 1, 2}, n2 = {1, 2, 3};
    int k = 10;
    Solution s;
    s.kSmallestPairs(n1, n2, k);
}