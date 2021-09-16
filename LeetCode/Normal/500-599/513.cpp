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
    int findBottomLeftValue(TreeNode *root)
    {
        queue<TreeNode *> tq;
        if (!root)
            return 0;
        int res = 0;
        tq.push(root);
        while (tq.size())
        {
            int num = tq.size();
            res = tq.front()->val;
            while (num--)
            {
                if (tq.front()->left)
                {
                    tq.push(tq.front()->left);
                }
                if (tq.front()->right)
                {
                    tq.push(tq.front()->right);
                }
                tq.pop();
            }
        }
        return res;
    }
};