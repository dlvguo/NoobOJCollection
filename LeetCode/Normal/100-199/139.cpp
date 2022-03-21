#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    typedef struct trieNode
    {
        unordered_map<char, trieNode *> children;
        bool isTail = false;
        char ch;
    } * TrieNode;

    // 构建字典树
    void CreateTree(TrieNode root, string str, int index)
    {
        TrieNode temp;
        // 说明不为空
        char ch = str[index];
        if (root->children.find(ch) != root->children.end())
        {
            temp = root->children[ch];
        }
        else
        {
            temp = new trieNode;
            temp->ch = ch;
            root->children[ch] = temp;
        }
        if (str.size() - 1 == index)
        {
            temp->isTail = true;
        }
        else
        {
            CreateTree(temp, str, index + 1);
        }
    }
    TrieNode root;

    bool tag[303] = {false};

    bool dfs(string &s, int posIndex)
    {
        if (posIndex == s.size())
            return true;
        if (tag[posIndex])
            return false;
        int index = posIndex;
        TrieNode temp = root;
        // 开始寻找
        while (index < s.size() && temp->children.find(s[index]) != temp->children.end())
        {
            // 说明是根
            temp = temp->children[s[index]];
            if (temp->isTail)
            {
                if (dfs(s, index + 1))
                    return true;
            }
            index++;
        }
        tag[posIndex] = true;
        return false;
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        root = new trieNode;
        for (auto word : wordDict)
        {
            CreateTree(root, word, 0);
        }
        return dfs(s, 0);
    }
};