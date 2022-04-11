#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    const string dict[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    int uniqueMorseRepresentations(vector<string> &words)
    {
        unordered_set<string> uset;
        for (auto word : words)
        {
            string temp = "";
            for (auto ch : word)
            {
                temp += dict[ch - 'a'];
            }
            uset.insert(temp);
        }
        return uset.size();
    }
};