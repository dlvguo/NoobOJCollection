#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> sset;
        unordered_set<string> vset;

        for (auto word : wordList)
            sset.insert(word);
        if (sset.find(endWord) == sset.end())
            return 0;
        queue<string> pq;
        pq.push(beginWord);
        vset.insert(beginWord);
        int res = 0, size = beginWord.size();
        while (pq.size())
        {
            res++;
            int num = pq.size();
            while (num--)
            {
                string word = pq.front();
                pq.pop();
                for (int i = 0; i < size; i++)
                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        if (ch != word[i])
                        {
                            string temp = word;
                            temp[i] = ch;
                            if (temp == endWord)
                                return res + 1;
                            if (sset.find(temp) != sset.end() && vset.find(temp) == vset.end())
                            {
                                vset.insert(temp);
                                pq.push(temp);
                            }
                        }
                    }
            }
        }
        return 0;
    }
};