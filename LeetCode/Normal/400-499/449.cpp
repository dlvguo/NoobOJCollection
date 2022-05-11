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
    string serialize(TreeNode *root)
    {
        string res;
        vector<int> arr;
        postOrder(root, arr);
        if (arr.size() == 0)
        {
            return res;
        }
        for (int i = 0; i < arr.size() - 1; i++)
        {
            res.append(to_string(arr[i]) + ",");
        }
        res.append(to_string(arr.back()));
        return res;
    }

    vector<string> split(const string &str, char dec)
    {
        int pos = 0;
        int start = 0;
        vector<string> res;
        while (pos < str.size())
        {
            while (pos < str.size() && str[pos] == dec)
            {
                pos++;
            }
            start = pos;
            while (pos < str.size() && str[pos] != dec)
            {
                pos++;
            }
            if (start < str.size())
            {
                res.emplace_back(str.substr(start, pos - start));
            }
        }
        return res;
    }

    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
        {
            return nullptr;
        }
        vector<string> arr = split(data, ',');
        stack<int> st;
        for (auto &str : arr)
        {
            st.emplace(stoi(str));
        }
        return construct(INT_MIN, INT_MAX, st);
    }

    void postOrder(TreeNode *root, vector<int> &arr)
    {
        if (root == nullptr)
        {
            return;
        }
        postOrder(root->left, arr);
        postOrder(root->right, arr);
        arr.emplace_back(root->val);
    }

    TreeNode *construct(int lower, int upper, stack<int> &st)
    {
        if (st.size() == 0 || st.top() < lower || st.top() > upper)
        {
            return nullptr;
        }
        int val = st.top();
        st.pop();
        TreeNode *root = new TreeNode(val);
        root->right = construct(val, upper, st);
        root->left = construct(lower, val, st);
        return root;
    }
};
