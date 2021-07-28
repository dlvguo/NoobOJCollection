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
    int findSecondMinimumValue(TreeNode *root)
    {
        if (!root->left)
            return -1;
        queue<TreeNode *> tq;
        tq.push(root);

        int first = -1, second = -1;
        while (tq.size())
        {
            TreeNode *t = tq.front();
            tq.pop();
            if (first == -1)
            {
                first = t->val;
            }
            else if (first > t->val)
            {
                second = first;
                first = t->val;
            }
            else if (t->val != first && (second == -1 || second > t->val))
            {
                second = t->val;
            }
            if (t->left)
            {
                tq.push(t->left);
                tq.push(t->right);
            }
        }
        return second;
    }
};