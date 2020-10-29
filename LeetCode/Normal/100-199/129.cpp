#include <bits/stdc++.h>
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
    long long len;
    int sumNumbers(TreeNode *root)
    {
        if (!root)
            return 0;
        len = 0;
        dfs(root, root->val);
        return len;
    }

    void dfs(TreeNode *root, long long num)
    {
        int count = 0;
        if (root->left)
        {
            dfs(root->left, num * 10 + root->left->val);
            count += 1;
        }
        if (root->right)
        {
            dfs(root->right, num * 10 + root->right->val);
            count += 1;
        }
        if (!count)
        {
            len += num;
        }
    }
};