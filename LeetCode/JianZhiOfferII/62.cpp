#include <iostream>
#include <vector>
using namespace std;
class Trie
{
public:
    /** Initialize your data structure here. */
    typedef struct trieNode
    {
        unordered_map<char, trieNode *> children;
        bool isTail = false;
        char ch;
    } * TrieNode;

    TrieNode root;

    Trie()
    {
        root = new trieNode;
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        CreateTree(root, word, 0);
    }

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

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode temp = root;
        int index = 0;
        // 开始寻找
        while (index < s.size() && temp->children.find(word[index]) != temp->children.end())
        {
            temp = temp->children[word[index]];
            index++;
        }
        if (index == word.size() && temp->isTail)
            return true;
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        return !search(prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */