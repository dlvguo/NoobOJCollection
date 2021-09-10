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
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> ans;
        queue<TreeNode *> tq;
        if (!root)
            return ans;
        tq.push(root);
        while (tq.size())
        {
            int _max = tq.front()->val, num = tq.size();
            while (num--)
            {
                TreeNode *p = tq.front();
                tq.pop();
                _max = max(p->val, _max);
                if (p->left)
                    tq.push(p->left);
                if (p->right)
                    tq.push(p->right);
            }
            ans.push_back(_max);
        }
        return ans;
    }
};