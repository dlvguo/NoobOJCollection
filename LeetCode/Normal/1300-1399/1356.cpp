#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct S
    {
        int val, num;
    };
    vector<int> sortByBits(vector<int> &arr)
    {
        vector<S> vts;
        for (int i = 0; i < arr.size(); i++)
        {
            S s;
            s.num = figure(arr[i]);
            s.val = arr[i];
            vts.push_back(s);
        }
        sort(vts.begin(), vts.end(), cmp);
        for (int i = 0; i < arr.size(); i++)
        {
            arr[i] = vts[i].val;
        }
        return arr;
    }

    static bool cmp(const S s1, const S s2)
    {
        return s1.num < s2.num || (s1.num == s2.num && s1.val < s2.val);
    }

    int figure(int n)
    {
        int count = 0;
        while (n)
        {
            count++;
            n = n & (n - 1);
        }
        return count;
    }
};