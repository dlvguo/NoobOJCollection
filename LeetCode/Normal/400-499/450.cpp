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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root->val == key)
        {
            if (!root->left)
                return root->right;
            if (!root->right)
                return root->left;
            //都不为空
            TreeNode *rl = root->right;
            while (rl->left)
            {
                rl = rl->left;
            }
            rl->left = root->left;
            return root->right;
        }
        else if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }
        else
            root->left = deleteNode(root->left, key);
        return root;
    }
};