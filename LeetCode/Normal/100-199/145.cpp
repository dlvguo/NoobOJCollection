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
    vector<int> postorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> s;
        vector<int> nums;
        TreeNode *pre = NULL;
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
                if (!root->right || pre == root->right)
                {
                    pre = root;
                    nums.push_back(root->val);
                    s.pop();
                    root = NULL;
                }
                else
                    root = root->right;
            }
        }
        return nums;
    }
};