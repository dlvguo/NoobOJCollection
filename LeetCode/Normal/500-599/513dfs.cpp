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
    int left, temp = 1;

    void dfs(int high, TreeNode *root)
    {
        if (!root)
            return;
        if (temp == high)
        {
            temp++;
            left = root->val;
        }
        dfs(high + 1, root->left);
        dfs(high + 1, root->right);
    }

    int findBottomLeftValue(TreeNode *root)
    {
        dfs(1, root);
        return left;
    }
};