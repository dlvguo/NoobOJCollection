#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int maxValue = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            maxValue = max(piles[i], maxValue);
        }
        int left=1,right=maxValue;
        while (left<=right)
        {
            int mid=(left+right)>>1;
            if(search(piles,mid)>h){
                left=mid+1;
            }
            else{
                maxValue=mid;
                right=mid-1;
            }
        }
        return maxValue;
    }

    int search(vector<int> &piles, int val)
    {
        int ans = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            ans += (piles[i] - 1) / val + 1;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> vts = {3, 6, 7, 11};
    int h = 8;
    s.minEatingSpeed(vts, h);
}