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
    bool isSymmetric(TreeNode *root)
    {
        return ismirror(root, root);
    }

    bool ismirror(TreeNode *p, TreeNode *q)
    {
        if (!p && !q) //都为NULL
            return true;
        if (!p || !q) //有一个为NULL
            return false;
        if (p->val == q->val)
            return ismirror(p->left, q->right) && ismirror(p->right, q->left);
        return false;
    }
};