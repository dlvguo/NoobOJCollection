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
    int dfs(TreeNode *root, int &k)
    {
        if (!root)
            return 0;
        int num = dfs(root->left, k);
        if (num)
            return num;
        if (k == 1)
            return root->val;
        k--;
        return dfs(root->right, k);
    }

    int kthLargest(TreeNode *root, int k)
    {
        return dfs(root,k);
    }
};