#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode *dfs(vector<int> preorder, vector<int> inorder, int left, int right, int preIndex)
{
    if (left > right)
        return NULL;
    TreeNode *bt = new TreeNode(preorder[preIndex]);
    int index = 0;
    for (int i = left; i <= right; i++)
    {
        if (preorder[preIndex] == inorder[i])
        {
            index = i;
            break;
        }
    }
    bt->left = dfs(preorder, inorder, left, index - 1, preIndex + 1);
    bt->right = dfs(preorder, inorder, index + 1, right, preIndex + index - left + 1);
    return bt;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    return dfs(preorder, inorder, 0, preorder.size() - 1, 0);
}