#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int hash[26] = {0};
    string originalDigits(string s)
    {
        string res = "";
        for (int i = 0; i < s.size(); i++)
        {
            hash[s[i] - 'a']++;
        }
        //判断 zero
        while (hash['z' - 'a'])
        {
            hash['z' - 'a']--;
            hash['e' - 'a']--;
            hash['r' - 'a']--;
            hash['o' - 'a']--;
            res.push_back('0');
        }
        //判断 four
        while (hash['u' - 'a'])
        {
            hash['f' - 'a']--;
            hash['o' - 'a']--;
            hash['u' - 'a']--;
            hash['r' - 'a']--;
            res.push_back('4');
        }
        //判断 six
        while (hash['x' - 'a'])
        {
            hash['s' - 'a']--;
            hash['i' - 'a']--;
            hash['x' - 'a']--;
            res.push_back('6');
        }
        //判断 two
        while (hash['w' - 'a'])
        {
            hash['t' - 'a']--;
            hash['w' - 'a']--;
            hash['o' - 'a']--;
            res.push_back('2');
        }
        //判断 five
        while (hash['f' - 'a'])
        {
            hash['f' - 'a']--;
            hash['i' - 'a']--;
            hash['v' - 'a']--;
            hash['e' - 'a']--;
            res.push_back('5');
        }
        //判断 three
        while (hash['r' - 'a'])
        {
            hash['t' - 'a']--;
            hash['h' - 'a']--;
            hash['r' - 'a']--;
            hash['e' - 'a'] -= 2;
            res.push_back('3');
        }
        //判断 one
        while (hash['o' - 'a'])
        {
            hash['o' - 'a']--;
            hash['n' - 'a']--;
            hash['e' - 'a']--;
            res.push_back('1');
        }
        //判断 seven
        while (hash['v' - 'a'])
        {
            hash['s' - 'a']--;
            hash['e' - 'a'] -= 2;
            hash['v' - 'a']--;
            hash['n' - 'a']--;
            res.push_back('7');
        }
        //判断 eight
        while (hash['t' - 'a'])
        {
            hash['e' - 'a']--;
            hash['i' - 'a']--;
            hash['g' - 'a']--;
            hash['h' - 'a']--;
            hash['t' - 'a']--;
            res.push_back('8');
        }
        //判断 nine
        while (hash['i' - 'a'])
        {
            hash['n' - 'a'] -= 2;
            hash['i' - 'a']--;
            hash['e' - 'a']--;
            res.push_back('9');
        }
        sort(res.begin(), res.end());
        return res;
    }
};