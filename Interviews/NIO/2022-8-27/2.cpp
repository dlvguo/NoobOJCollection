#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums;
    int n;
    while (cin >> n)
    {
        nums.push_back(n);
    }

    nums.pop_back();

    int _max = 0;
    for (auto num : nums)
        _max = max(num, _max);

    vector<int> res;

    cout << "[";
    for (int i = 0; i < nums.size(); i++)
    {
        if ((n + nums[i]) >= _max)
        {
            cout << "True";
        }
        else
        {
            cout << "False";
        }
        if (i != nums.size() - 1)
        {
            cout << ", ";
        }
        else
        {
            cout << "]" << endl;
        }
    }
}