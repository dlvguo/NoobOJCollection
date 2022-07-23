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
    // map不存在默认为0
    map<int, int> res;

    int ans = 0;
    int total = 0;

    int pathSum(TreeNode *root, int sum)
    {

        res[0] = 1;
        dfs(root, sum);
        return ans;
    }

    void dfs(TreeNode *root, int sum)
    {
        if (!root)
            return;
        total += root->val;
        int key = total - sum;
        if (res[key])
        {
            ans += res[key];
        }
        res[total]++;
        dfs(root->left, sum);
        dfs(root->right, sum);
        res[total]--;
        total -= root->val;
    }
};
