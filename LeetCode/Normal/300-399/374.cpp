#include <bits/stdc++.h>
using namespace std;
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution
{
public:
    int guessNumber(int n)
    {
        long long l = 1, h = n, m, flag;
        do
        {
            m = (l + h) / 2;
            flag = guess(m);
            if (flag == -1)
            {
                h = m - 1;
            }
            else if (flag == 1)
            {
                l = m + 1;
            }
        } while (flag != 0);
        return m;
    }
    int guess(int num)
    {
        return 0;
    }
};