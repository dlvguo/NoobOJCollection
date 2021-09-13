#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxmiumScore(vector<int> &cards, int cnt)
    {
        sort(cards.rbegin(), cards.rend());
        //遇见奇数可能考虑 去除最后面的一个偶数或者最后一个奇数
        int res = 0, len = cnt, lsto = -1, lste = -1;
        for (int i = 0; i < cnt; i++)
        {
            res += cards[i];
            if (cards[i] % 2)
                lsto = i;
            else
                lste = i;
        }
        if (res % 2 == 0)
            res;
        //去除奇数 找到后面的偶数
        int nres = res - cards[lsto];
        bool nrestag = false;
        for (int i = cnt; i < cards.size(); i++)
        {
            if (cards[i] % 2 == 0)
            {
                nrestag = true;
                nres += cards[i];
            }
        }
        if (nrestag == false)
            nres = 0;

        //去除偶数 找到后面奇数
        if (lste == -1)
            return nres;
    }
};

int main()
{
    Solution s;
    vector<int> v = {3, 3, 1};
    cout << s.maxmiumScore(v, 1);
}