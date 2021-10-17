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
    int val = 0;
    int _k = 0;
    void dfs(TreeNode *root)
    {
        if (!root)
            return;
        if (k <= 0)
            return;
        dfs(root->left);
        if (_k == 1)
        {
            val = root->val;
            _k--;
            return;
        }
        _k--;
        dfs(root->right);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        _k = k;
        dfs(root);
        return val;
    }
};