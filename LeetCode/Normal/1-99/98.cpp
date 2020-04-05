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
    bool isValidBST(TreeNode *root)
    {
        bool tag = false;
        int pre;
        stack<TreeNode *> s;
        while (!s.empty() || root)
        {
            if (root)
            {
                s.push(root);
                root = root->left;
            }
            else
            {
                root = s.top();
                if (!tag)
                {
                    pre = root->val;
                    tag = true;
                }
                else if (root->val <= pre)
                    return false;
                else
                    pre = root->val;
                root = root->right;
                s.pop();
            }
        }
        return true;
    }
};