#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
    {
        vector<int> diff(n + 2, 0);
        vector<int> answers(n, 0);
        for (auto book : bookings)
        {
            diff[book[0]] += book[2];
            diff[book[1]+1] -= book[2];
        }
        answers[0] = diff[1];
        for (int i = 1; i < n; i++)
        {
            answers[i] = answers[i - 1] + diff[i + 1];
        }
        return answers;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> books;
}