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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        //根据二叉搜索树 快很多
        int small, big;
        if (p->val > q->val)
        {
            small = q->val;
            big = p->val;
        }
        else
        {
            small = p->val;
            big = q->val;
        }
        while (root)
        {
            if (root->val < small)
            {
                root = root->right;
            }
            else if (root->val > big)
            {
                root = root->left;
            }
            else
                return root;
        }
        return root;
    }
};