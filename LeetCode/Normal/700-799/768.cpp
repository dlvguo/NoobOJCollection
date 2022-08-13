#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        int ans = 0;
        stack<int> st;
        for (int i = 0; i < arr.size(); i++)
        {
            if (st.empty() || st.top() <= arr[i])
                st.emplace(arr[i]);
            else
            {
                int mx = st.top();
                st.pop();
                while (st.size() && st.top() > arr[i])
                {
                    st.pop();
                }
                st.emplace(mx);
            }
        }

        return st.size();
    }
};