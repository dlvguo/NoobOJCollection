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
    int _min = 1e9;
    int pre = -1e9;
    void orderSearch(TreeNode *root)
    {
        if (!root)
            return;
        orderSearch(root->left);
        _min = min(root->val - pre, _min);
        pre = root->val;
        orderSearch(root->right);
    }
    int minDiffInBST(TreeNode *root)
    {
        orderSearch(root);
        return _min;
    }
};