#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;
class Solution
{
public:
    int maxProduct(vector<string> &words)
    {
        vector<int> wordsBits;
        for (auto word : words)
        {
            int l = 0;
            // 遍历每一个字母
            for (auto ch : word)
            {
                int num = ch - 'a';
                //看看当前位数是否有值
                if ((1 << num) & l)
                {
                    continue;
                }
                // 值赋过去
                l ^= (1 << num);
            }
            wordsBits.push_back(l);
        }
        int _max = 0;
        for (int i = 0; i < wordsBits.size(); i++)
        {
            for (int j = i + 1; j < wordsBits.size(); j++)
            {
                if (wordsBits[i] & wordsBits[j])
                    continue;
                int num=words[i].size() * words[j].size();
                if(_max<num)
                    _max=num;
            }
        }
        return _max;
    }
};