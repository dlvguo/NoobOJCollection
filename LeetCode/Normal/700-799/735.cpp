#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> st;
        st.push_back(asteroids[0]);
        for (int i = 1; i < asteroids.size(); i++)
        {
            bool isAlive = true;

            while (asteroids[i] < 0 && st.size() && st.back() > 0)
            {
                if (st.back() > -asteroids[i])
                {
                    isAlive = false;
                    break;
                }
                else if (st.back() < -asteroids[i])
                {
                    st.pop_back();
                }
                else
                {
                    st.pop_back();
                    isAlive = false;
                    break;
                }
            }
            if (isAlive)
                st.push_back(asteroids[i]);
        }
        return st;
    }
};