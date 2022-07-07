#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    typedef struct tire
    {
        bool isRoot = false;
        tire *children[26] = {NULL};
    } * Tire;

    void createTire(Tire root, string str)
    {
        for (int i = 0; i < str.size(); i++)
        {
            int num = str[i] - 'a';
            Tire child = root->children[num];
            if (child == NULL)
            {
                child = new tire;
            }
            root->children[num] = child;
            root = child;
        }
        root->isRoot = true;
    }

    string search(Tire root, string str)
    {
        string res = "";
        int i = 0;
        while (i < str.size() && root && !(root->isRoot))
        {
            int num = str[i] - 'a';
            root = root->children[num];
            res.push_back(str[i++]);
        }
        // 考虑说 词根可能比原来的长 那就不考虑了 边界问题
        if (!root || i == str.size())
            return str;
        return res;
    }

    string replaceWords(vector<string> &dictionary, string sentence)
    {
        string res = "";
        Tire root = new tire;
        for (auto dict : dictionary)
            createTire(root, dict);
        string temp = "";
        for (auto ch : sentence)
        {
            if (ch == ' ')
            {
                if (res.size())
                    res += " ";
                res += search(root, temp);
                temp.clear();
            }
            else
            {
                temp.push_back(ch);
            }
        }
        res += " ";
        res += search(root, temp);
        return res;
    }
};