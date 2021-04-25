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
    void inorder(TreeNode *node, vector<int> &res)
    {
        if (node == nullptr)
        {
            return;
        }
        inorder(node->left, res);
        res.push_back(node->val);
    }

    TreeNode *increasingBST(TreeNode *root)
    {
        vector<int> res;
        inorder(root, res);

        TreeNode *dummyNode = new TreeNode(-1);
        TreeNode *currNode = dummyNode;
        for (int value : res)
        {
            currNode->right = new TreeNode(value);
            currNode = currNode->right;
        }
        return dummyNode->right;
    }
};
