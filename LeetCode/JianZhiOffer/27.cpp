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
    void dfs(TreeNode *root)
    {
        if (!root)
            return;
        TreeNode *p = root->left;
        root->left = root->right;
        root->right = p;
        dfs(root->left);
        dfs(root->right);
    }

    TreeNode *mirrorTree(TreeNode *root)
    {
        dfs(root);
        return root;
    }
};