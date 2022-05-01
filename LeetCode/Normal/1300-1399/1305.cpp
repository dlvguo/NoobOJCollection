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
    vector<int> temp, res;
    int index = 0;

    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        inorder(root->left);
        temp.push_back(root->val);
        inorder(root->right);
    }

    void inorder2(TreeNode *root)
    {
        if (!root)
            return;
        inorder2(root->left);
        while (index < temp.size() && temp[index] < root->val)
        {
            res.push_back(temp[index++]);
        }
        res.push_back(root->val);
        inorder2(root->right);
    }

    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        inorder(root1);
        inorder2(root2);
        while (index < temp.size())
        {
            res.push_back(temp[index++]);
        }
        return res;
    }
};