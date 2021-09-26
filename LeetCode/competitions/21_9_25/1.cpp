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
    unordered_map<int, int> umap;

    void dfs(TreeNode *root)
    {
        if (!root)
            return;
        umap[root->val]++;
        dfs(root->left);
        dfs(root->right);
    }

    int numColor(TreeNode *root)
    {
        dfs(root);
        return umap.size();
    }
};