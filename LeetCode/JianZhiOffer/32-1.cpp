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
    vector<int> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<int> v;
        if (root)
            q.push(root);
        while (!q.empty())
        {
            int count = q.size();
            while (count--)
            {
                root = q.front();
                q.pop();
                v.push_back(root->val);
                if (root->left)
                    q.push(root->left);
                if (root->right)
                    q.push(root->right);
            }
        }
        return v;
    }
};