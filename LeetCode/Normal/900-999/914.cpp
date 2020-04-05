#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
public:
    int gcd(int x, int y)
    {
        if (x % y)
        {
            return gcd(y, x % y);
        }
        return y;
    }

    bool hasGroupsSizeX(vector<int> &deck)
    {
        if (deck.size() == 1)
            return false;
        set<int> s;
        for (int i = 0; i < deck.size(); i++)
        {
            s.insert(deck[i]);
        }

        set<int>::iterator it = s.begin();

        int preSum = s.count(*it++), sum;
        while (it != s.end())
        {
            sum = s.count(*it);
            preSum = preSum > sum ? gcd(preSum, sum) : gcd(sum, preSum);
            if (preSum < 2)
                return false;
            it++;
        }
        return true;
    }
};

int main()
{
    vector<int> v({1, 2, 3, 4, 4, 3, 2, 1});
    Solution s1;
    s1.hasGroupsSizeX(v);
    system("pause");
    return 0;
}
