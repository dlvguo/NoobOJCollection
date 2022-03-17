#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    typedef struct node
    {
        char ch;
        bool isRoot = false;
        map<char, node *> children;
    } * Node;

    string longestWord(vector<string> &words)
    {
        Node root = new node;
        for (auto word : words)
        {
            createTree(root, 0, word);
        }
        search(root);
        return res;
    }

    string res = "", temp = "";

    void search(Node root)
    {
        if (temp.size() > res.size())
            res = temp;
        for (auto child : root->children)
        {
            //只有root 才有继续的必要
            if (child.second->isRoot)
            {
                temp.push_back(child.second->ch);
                search(child.second);
                temp.pop_back();
            }
        }
    }
    void createTree(Node root, int index, string &str)
    {
        if (root->children.find(str[index]) == root->children.end())
        {
            Node n = new node;
            n->ch = str[index];
            root->children[str[index++]] = n;
            if (index == str.size())
            {
                n->isRoot = true;
                return;
            }
            else
            {
                createTree(n, index, str);
            }
        }
        else
        {
            Node n = root->children[str[index++]];
            if (str.size() == index)
            {
                n->isRoot = true;
                return;
            }
            else
            {
                createTree(n, index, str);
            }
        }
    }
};
