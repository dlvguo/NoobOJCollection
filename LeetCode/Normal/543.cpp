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
    int result = 0;

    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        if (result < left + right)
            result = left + right;
        return left > right ? left + 1 : right + 1;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        dfs(root);
        return result;
    }
};