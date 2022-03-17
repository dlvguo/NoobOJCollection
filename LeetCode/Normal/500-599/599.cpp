#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {
        unordered_map<string, int> maps;
        for (int i = 0; i < list1.size(); i++)
        {
            maps[list1[i]] = i;
        }
        int minValue = list1.size() + list2.size();
        vector<string> res;
        for (int i = 0; i < list2.size(); i++)
        {
            if (maps.find(list2[i]) != maps.end())
            {
                int temp = maps[list2[i]] + i;
                if (temp == minValue)
                    res.push_back(list2[i]);
                else if (temp < minValue)
                {
                    minValue = temp;
                    res.clear();
                    res.push_back(list2[i]);
                }
            }
        }
        return res;
    }
};