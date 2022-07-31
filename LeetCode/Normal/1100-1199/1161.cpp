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
    int maxLevelSum(TreeNode *root)
    {
        int _max = root->val;
        int cen = 1;
        int pcen = 1;
        queue<TreeNode *> tq;
        tq.push(root);
        while (tq.size())
        {
            int count = tq.size();
            int temp = 0;
            while (count--)
            {
                TreeNode *t = tq.front();
                tq.pop();
                temp += t->val;
                if (t->left)
                    tq.push(t->left);
                if (t->right)
                    tq.push(t->right);
            }
            if(temp>_max){
                _max=temp;
                pcen=cen;
            }
            cen++;
        }
        return pcen;
    }
};