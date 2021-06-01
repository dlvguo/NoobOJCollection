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
    bool isCousins(TreeNode *root, int x, int y)
    {
        if (!root || root->val == x || root->val == y)
            return false;
        queue<TreeNode *> tq;
        int f = -1;
        tq.push(root);
        while (tq.size())
        {
            int count = tq.size();

            TreeNode *t;
            while (count--)
            {
                t = tq.front();
                tq.pop();
                if (t->left)
                {
                    if (t->left->val == x || t->left->val == y)
                    {
                        if (f != -1)
                            return true;
                        else
                        {
                            f = t->val;
                        }
                    }
                    tq.push(t->left);
                }
                if (t->right)
                {
                    if (t->right->val == x || t->left->val == y)
                    {
                        if (f != -1)
                            return !(f == t->val); //注意括号内取！
                        else
                        {
                            f = t->val;
                        }
                    }
                    tq.push(t->right);
                }
            }
            //说明找到一个 跳出
            if (f != -1)
                break;
        }
        return false;
    }
};