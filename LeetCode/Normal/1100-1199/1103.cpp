#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> distributeCandies(int candies, int num_people)
    {
        int count = 1; //计算能完整分配的次数
        while ((count + 1) * count / 2 < candies)
        {
            count++;
        }
        if ((count + 1) * count / 2 != candies)
            count--;
        int round = count / num_people; //能完整分配的回合数
        vector<int> v;
        v.resize(num_people); //先分配好size效率比push_back高
        for (int i = 1; i <= num_people; i++)
        {
            int people = 0;
            if (round)
            {
                people += ((round - 1) * round / 2) * num_people + i * round;
            }
            if (count % num_people >= i) //说明在非完整回合下 还有余下位置
            {
                people += round * num_people + i;
            }
            candies -= people;
            v[i - 1] = people;
        }
        if (candies != 0) //如果还有剩余糖果分配在count+1 位置
        {
            int index = (count + 1) % num_people;
            if (index == 0)
                index = num_people;
            v[index - 1] += candies;
        }
        return v;
    }
};