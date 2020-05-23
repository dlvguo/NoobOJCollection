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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return pre_order(0, inorder.size() - 1, 0, inorder.size() - 1, preorder, inorder);
    }

    TreeNode *pre_order(int leftpre, int rightpre, int leftin, int rightin, vector<int> &pre, vector<int> &in)
    {
        if (leftpre > rightpre || leftin > rightin)
            return NULL;
        TreeNode *root = new TreeNode(pre[leftpre]);
        int rootin = leftin;
        while (rootin <= rightin && in[rootin] != pre[leftpre])
            rootin++;
        int left = rootin - leftin;
        root->left = pre_order(leftpre + 1, leftpre + left, leftin, rootin - 1, pre, in);
        root->right = pre_order(leftpre + left + 1, rightpre, rootin + 1, rightin, pre, in);
        return root;
    }
};