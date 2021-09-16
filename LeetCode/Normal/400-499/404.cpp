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
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (!root)
            return 0;
        int l = sumOfLeftLeaves(root->left), r = sumOfLeftLeaves(root->right);
        if (root->left && !root->left->left && !root->left->right)
            return l + r + root->left->val;
        return l + r;
    }
};