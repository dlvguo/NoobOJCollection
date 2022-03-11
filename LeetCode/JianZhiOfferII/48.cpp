#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == nullptr)
        {
            return "#";
        }
        string leftStr = serialize(root->left);
        string rightStr = serialize(root->right);
        return to_string(root->val) + "," + leftStr + "," + rightStr;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        cout << data << endl;
        // 分割字符串
        vector<string> dataArray{""};
        for (auto &ch : data)
        {
            if (ch == ',')
            {
                dataArray.push_back("");
            }
            else
            {
                dataArray.back().push_back(ch);
            }
        }
        int i = 0;
        return dfs(dataArray, i);
    }

private:
    TreeNode *dfs(vector<string> &strs, int &i)
    {
        string str = strs[i];
        i++;
        if (str == "#")
        {
            return nullptr;
        }

        TreeNode *node = new TreeNode(stoi(str));
        node->left = dfs(strs, i);
        node->right = dfs(strs, i);
        return node;
    }