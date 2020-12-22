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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        deque<TreeNode *> dq;
        vector<vector<int>> vts;
        dq.push_back(root);
        bool isLeft = true;
        while (dq.size())
        {
            int count = dq.size();
            vector<int> v;
            if (isLeft)
            {
                while (count--)
                {
                    TreeNode *temp = dq.front();
                    dq.pop_front();
                    v.push_back(temp->val);
                    if (temp->left)
                        dq.push_back(temp->left);
                    if (temp->right)
                        dq.push_back(temp->right);
                }
            }
            else
            {
                while (count--)
                {
                    TreeNode *temp = dq.back();
                    dq.pop_back();
                    v.push_back(temp->val);
                    if (temp->right)
                        dq.push_front(temp->right);
                    if (temp->left)
                        dq.push_front(temp->left);
                }
            }
            isLeft = !isLeft;
            vts.push_back(v);
        }
        return vts;
    }
};