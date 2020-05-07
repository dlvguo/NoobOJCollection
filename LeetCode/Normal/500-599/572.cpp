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
    bool isSearch = false;
    //递归大法
    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        if (!s || !t)
            return s == t;
        //判断是否是搜索
        if (isSearch)
        {
            if (s->val != t->val)
                return false;
            return isSubtree(s->left, t->left) && isSubtree(s->right, t->right);
        }
        bool tag = false;
        //值相同就说明 可能这里开始就算根节点于是有
        if (s->val == t->val)
        {
            isSearch = true;
            tag = isSubtree(s->left, t->left) && isSubtree(s->right, t->right);
            if (tag)
                return tag;
            isSearch = false;
        }
        //可能在左
        tag = isSubtree(s->left, t);
        return tag ? tag : isSubtree(s->right, t);
    }
};