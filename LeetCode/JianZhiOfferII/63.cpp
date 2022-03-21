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

    TrieNode root;

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

    string search(string word)
    {
        TrieNode temp = root;
        int index = 0;
        string res;
        // 开始寻找
        while (index < word.size() && temp->children.find(word[index]) != temp->children.end())
        {
            temp = temp->children[word[index]];
            res.push_back(temp->ch);
            if(temp->isTail)
                break;
            index++;
        }
        if (temp->isTail)
            return res;
        return word;
    }

    string replaceWords(vector<string> &dictionary, string sentence)
    {
        root = new trieNode;
        // 新建字典
        for (auto word : dictionary)
        {
            CreateTree(root, word, 0);
        }
        string res;
        string temp;
        for (int i = 0; i < sentence.size(); i++)
        {
            if (sentence[i] == ' ')
            {
                res += search(temp);
                res += " ";
                temp.clear();
            }
            else
                temp.push_back(sentence[i]);
        }
        res += search(temp);
        return res;
    }
};