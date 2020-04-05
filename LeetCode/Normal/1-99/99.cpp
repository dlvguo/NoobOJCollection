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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> nums;
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
                nums.push_back(root->val);
                root = root->right;
                s.pop();
            }
        }

        return nums;
    }
};