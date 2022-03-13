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
    int res;
    int maxPathSum(TreeNode *root)
    {
        res = root->val;
        dfs(root);
        return res;
    }

    void dfs(TreeNode *root)
    {
        if (!root)
            return;
        int l = 0, r = 0;
        int temp = root->val;
        if (root->left)
        {
            dfs(root->left);
            if (root->left->val > 0)
            {
                l = root->left->val;
                temp += l;
            }
        }
        if (root->right)
        {
            dfs(root->right);
            if (root->right->val > 0)
            {
                r = root->right->val;
                temp += r;
            }
        }
        res = max(res, temp);
        root->val += max(l, r);
    }
};