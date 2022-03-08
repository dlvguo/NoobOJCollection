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
    int maxDeep = 0, res = 0;
    int findBottomLeftValue(TreeNode *root)
    {
        dfs(root, 0);
        return res;
    }
    void dfs(TreeNode *root, int deep)
    {
        if (!root)
            return;
        if (deep == maxDeep)
        {
            res = root->val;
            maxDeep++;
        }
        dfs(root->left, deep + 1);
        dfs(root->right, deep + 1);
    }
};