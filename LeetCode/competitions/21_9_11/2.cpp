#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxmiumScore(vector<int> &cards, int cnt)
    {
        sort(cards.rbegin(), cards.rend());
        int ans = 0, prej = -1, preo = -1, lstj = -1, lsto = -1;
        for (int i = 0; i < cnt; i++)
        {
            ans += cards[i];
            //说明奇数
            if (cards[i] % 2)
                prej = i;
            else
                preo = i;
        }
        if (ans % 2 == 0)
            return ans;
        for (int i = cnt; i < cards.size(); i++)
        {
            //说明奇数
            if (cards[i] % 2 && lstj == -1)
                lstj = i;
            if (cards[i] % 2 == 0 && lsto == -1)
                lsto = i;
            if (lstj != -1 && lsto != -1)
                break;
        }
        int nres = 0;
        if (prej != -1 && lsto != -1)
        {
            nres = ans - cards[prej] + cards[lsto];
        }
        if (preo != -1 && lstj != -1)
        {
            nres = max(nres, ans - cards[preo] + cards[lstj]);
        }
        return nres;
    }
};