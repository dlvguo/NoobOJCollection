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
    int res = 0, mask = 1;

    int sumRootToLeaf(TreeNode *root)
    {
        dfs(root);

        return res;
    }

    void dfs(TreeNode *root)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
            res += mask;
        if (root->left)
        {
            mask = mask << 1;
            dfs(root->left);
            mask = mask >> 1;
        }
        if (root->right)
        {
            mask = mask << 1 + 1;
            dfs(root->right);
            mask = mask >> 1;
        }
    }
};