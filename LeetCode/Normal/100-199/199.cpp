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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> nums;
        if (!root)
            return nums;
        queue<TreeNode *> tq;
        tq.push(root);
        while (tq.size())
        {
            int count = tq.size();
            nums.push_back(tq.front()->val);
            while (count--)
            {
                root = tq.front();
                tq.pop();
                if (root->right)
                    tq.push(root->right);
                if (root->left)
                    tq.push(root->left);
            }
        }
        return nums;
    }
};