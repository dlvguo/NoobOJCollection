#include <bits/stdc++.h>
using namespace srd;
class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> ret;
        if (words.size() == 0) //判断words为空,因为下面用到了words[0]
            return ret;

        int word_size = words[0].size();
        int word_num = words.size();

        unordered_map<string, int> m1; //构造hashmap
        for (int i = 0; i < word_num; i++)
            m1[words[i]]++;

        unordered_map<string, int> m2;
        for (int i = 0; (i + word_size * word_num) <= s.size(); i++)
        { //截取的s符合题意
            int j = 0;
            for (j = i; j < (i + word_size * word_num); j = j + word_size)
            { //分段判断
                string temp_str = s.substr(j, word_size);
                if (m1[temp_str] == 0)
                { // m1中没有截取的串，直接跳出
                    break;
                }
                else
                {
                    m2[temp_str]++;
                    if (m1[temp_str] < m2[temp_str]) //重复次数过多，也跳出
                        break;
                }
            }

            if (j == (i + word_size * word_num)) //每一段都符合，则加入答案
                ret.push_back(i);

            m2.clear(); //清空m2
        }
        return ret;
    }
};