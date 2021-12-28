#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    typedef struct dictTree
    {
        bool tag;
        vector<dictTree *> children;
        dictTree()
        {
            this->tag = false;
            this->children = vector<dictTree *>(26, nullptr);
        }
    } * DictTree;
    DictTree droot = new dictTree();

    bool static cmp(const string &s1, const string &s2)
    {
        if (s1.size() == s2.size())
            return s1 < s2;
        return s1.size() < s2.size();
    }

    bool dfs(const string &str, int index, DictTree root)
    {
        if (!root || index == str.size())
            return false;
        char ch = str[index];
        DictTree dt = root->children[ch - 'a'];
        // 找不到
        if (!dt)
            return false;
        if (dt->tag)
        {
            // 最后一个
            if (index == str.size() - 1 || dfs(str, index + 1, droot))
                return true;
        }
        return dfs(str, index + 1, dt);
    }

    void buildTree(const string &str)
    {
        DictTree root = droot;
        for (int i = 0; i < str.size(); i++)
        {
            char ch = str[i];
            DictTree dt = root->children[ch - 'a'];
            if (dt)
            {
                root = dt;
            }
            else
            {
                DictTree temp = new dictTree();
                root->children[ch - 'a'] = temp;
                root = temp;
            }
        }
        root->tag = true;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        sort(words.begin(), words.end(), cmp);
        vector<string> res;
        for (int i = 0; i < words.size(); i++)
        {
            if (dfs(words[i], 0, droot))
            {
                res.push_back(words[i]);
            }
            // 如果一个已经有的话 说明能由短的构成 就不需要了 免得过于慢
            else
                buildTree(words[i]);
        }
        return res;
    }
};
