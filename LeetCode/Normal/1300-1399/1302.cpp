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
    int _max = 0, res = 0;

    void deepestLeavesSum(TreeNode *root, int deep)
    {
        if (!root)
            return;
        if (deep == _max)
        {
            res += root->val;
        }
        else if (deep > _max)
        {
            _max = deep;
            res = root->val;
        }
        deepestLeavesSum(root->left, deep + 1);
        deepestLeavesSum(root->right, deep + 1);
    }

    int deepestLeavesSum(TreeNode *root)
    {
        deepestLeavesSum(root, 1);
        return res;
    }
};