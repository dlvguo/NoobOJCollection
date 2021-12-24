#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    struct dayapple
    {
        int appNum, outday;
        dayapple(int aN, int od) : appNum(aN), outday(od) {}
        bool operator<(const dayapple &da) const
        {
            if (outday != da.outday)
                return outday > da.outday;
            return appNum > da.appNum;
        }
    };

    int eatenApples(vector<int> &apples, vector<int> &days)
    {
        int res = 0;
        priority_queue<dayapple> pq;
        int i;
        for (i = 0; i < apples.size(); i++)
        {
            dayapple ap(apples[i], i + days[i]);
            pq.push(ap);
            while (pq.size())
            {
                dayapple temp = pq.top();
                pq.pop();
                if (temp.outday <= i || temp.appNum == 0)
                {
                    continue;
                }
                temp.appNum--;
                res++;
                if (temp.appNum)
                    pq.push(temp);
                break;
            }
        }
        while (pq.size())
        {
            dayapple temp = pq.top();
            pq.pop();
            if (temp.outday <= i || temp.appNum == 0)
            {
                continue;
            }
            temp.appNum--;
            res++;
            i++;
            if (temp.appNum)
                pq.push(temp);
        }
        return res;
    }
};