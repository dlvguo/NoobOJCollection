#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int> &energy, vector<int> &experience)
    {

        int ans = 0;
        for (int i = 0; i < energy.size(); i++)
        {

            if (initialEnergy <= energy[i])
            {
                int ie = energy[i] - initialEnergy + 1;
                ans += ie;

                initialEnergy += ie;
            }
            if (initialExperience <= experience[i])
            {
                int iexp = experience[i] - initialExperience + 1;
                ans += iexp;
                initialExperience += iexp;
            }
            initialEnergy -= energy[i];
            initialExperience += experience[i];
        }
        return ans;
    }
};