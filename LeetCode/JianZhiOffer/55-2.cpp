#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;
        int left = dfs(root->left), right = dfs(root->right);
        if (left == -1 || right == -1 || fabs(left - right) > 1)
            return -1;
        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode *root)
    {
        return dfs(root) > -1;
    }
};