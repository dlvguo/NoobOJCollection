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
    bool isEvenOddTree(TreeNode *root)
    {
        int index = 0;
        int jo = 0;
        queue<TreeNode *> tq;
        tq.push(root);

        while (tq.size())
        {
            int count = tq.size();
            int val;
            // 奇数层 全偶 递减
            if (index % 2)
            {
                val = 1e6 + 1;
                while (count--)
                {
                    TreeNode *temp = tq.front();
                    tq.pop();
                    if (val <= temp->val || temp->val % 2)
                    {
                        return false;
                    }
                    val = temp->val;
                    if (temp->left)
                        tq.push(temp->left);
                    if (temp->right)
                        tq.push(temp->right);
                }
            }
            // 偶数层 全奇 递增
            else
            {
                val = 0;
                while (count--)
                {
                    TreeNode *temp = tq.front();
                    tq.pop();
                    if (val >= temp->val || temp->val % 2 == 0)
                    {
                        return false;
                    }
                    val = temp->val;
                    if (temp->left)
                        tq.push(temp->left);
                    if (temp->right)
                        tq.push(temp->right);
                }
            }
            index++;
        }
        return true;
    }
};