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
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode *temp = new TreeNode(val);
            temp->left = root;
            return temp;
        }
        queue<TreeNode *> tq;
        tq.push(root);
        //注意下标即可
        depth -= 2;
        while (depth)
        {
            int size = tq.size();
            while (size--)
            {
                TreeNode *temp = tq.front();
                tq.pop();
                if (temp->left)
                    tq.push(temp->left);
                if (temp->right)
                    tq.push(temp->right);
            }
            depth--;
        }
        if (tq.size())
        {
            int size = tq.size();
            while (size--)
            {
                TreeNode *temp = tq.front();
                tq.pop();
                TreeNode *temp1 = new TreeNode(val);
                TreeNode *temp2 = new TreeNode(val);
                temp1->left = temp->left;
                temp2->right = temp->right;
                temp->left = temp1;
                temp->right = temp2;
            }
        }
        return root;
    }
};