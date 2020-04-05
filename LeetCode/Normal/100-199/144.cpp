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
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> nums;
        stack<TreeNode *> s;
        while (!s.empty() || root)
        {
            if (root)
            {
                nums.push_back(root->val);
                if (root->right)
                    s.push(root->right);
                root = root->left;
            }
            else
            {
                root = s.top();
                s.pop();
            }
        }

        return nums;
    }
};