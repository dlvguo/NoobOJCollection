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
    TreeNode *pre ;
    TreeNode *increasingBST(TreeNode *root)
    {
        TreeNode *temp=new TreeNode(-1);
        pre = temp;
        if (!root)
            return root;
        inSearch(root);
        return temp->right;
    }
    void inSearch(TreeNode *root)
    {
        if (!root)
            return;
        inSearch(root->left);
        pre->right = root;
        root->left = NULL;
        pre = root;
        inSearch(root->right);
    }
};