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
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        stack<TreeNode *> st;
        TreeNode *prev = nullptr, *curr = root;
        while (!st.empty() || curr != nullptr)
        {
            while (curr != nullptr)
            {
                st.emplace(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            if (prev == p)
            {
                return curr;
            }
            prev = curr;
            curr = curr->right;
        }
        return nullptr;
    }
};
