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
    TreeNode *search(int il, int ir, int pl, int pr, vector<int> &inorder, vector<int> &postorder)
    {
        if (il > ir)
            return NULL;
        //获取根节点
        TreeNode *root = new TreeNode(postorder[pr]);

        //寻找那个
        int i;
        for (i = il; i < ir; i++)
        {
            if (inorder[i] == postorder[pr])
                break;
        }
        root->left = search(il, i - 1, pl, pl + i - 1 - il, inorder, postorder);

        root->right = search(i + 1, ir, pl + i - il, pr - 1, inorder, postorder);

        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.size() == 0)
            return NULL;
        return search(0, inorder.size() - 1, 0, inorder.size() - 1, inorder, postorder);
    }
};