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
    bool Judge(TreeNode *A, TreeNode *B)
    {
        if (!B)
            return true;
        if (!A)
            return false;

        if (A->val == B->val)
        {
            return Judge(A->left, B->left) && Judge(A->right, B->right);
        }
        return false;
    }

    bool isSubStructure(TreeNode *A, TreeNode *B)
    {
        if (!B || !A)
            return false;
        if (A->val == B->val) //可能在这个结构 也可能不在这个结构
            if (Judge(A, B))
                return true;
        if (isSubStructure(A->left, B))
            return true;
        return isSubStructure(A->right, B);
    }
};