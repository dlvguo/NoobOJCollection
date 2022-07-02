#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    unordered_map<int, int> _map;
    int max = 0;
    unordered_set<int> rset;
    int dfs(TreeNode *root)
    {
        int left = 0, right = 0;
        if (root->left)
            left = dfs(root->left);

        if (root->right)
            right = dfs(root->right);

        int t = root->val + left + right;
        _map[t]++;
        if (_map[t] == max)
            rset.insert(t);
        else if (_map[t] > max)
        {
            max = _map[t];
            rset.clear();
            rset.insert(t);
        }
        return t;
    }

    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        dfs(root);
        vector<int> res;
        for (auto s : rset)
            res.push_back(s);
        return res;
    }
};