#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int ans = 0;

    int findTilt(TreeNode *root)
    {
        dfs(root);
        return ans;
    }

    int dfs(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int sumLeft = dfs(node->left);
        int sumRight = dfs(node->right);
        ans += abs(sumLeft - sumRight);
        return sumLeft + sumRight + node->val;
    }
};