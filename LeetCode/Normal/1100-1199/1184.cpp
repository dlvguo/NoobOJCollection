#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // 注意下标问题
    int distanceBetweenBusStops(vector<int> &distance, int start, int destination)
    {
        //向右走
        int temp = start;

        int rres = 0;

        while (temp != destination)
        {
            rres += distance[temp++];
            if (temp == distance.size())
                temp = 0;
        }
        temp = start;
        int lres = 0;
        while (temp != destination)
        {
            temp--;
            if (temp < 0)
                temp = distance.size() - 1;
            lres += distance[temp];
        }
        if (rres < lres)
            return rres;
        return lres;
    }
};