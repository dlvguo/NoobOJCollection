#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> pancakeSort(vector<int> &arr)
    {
        vector<int> res;
        for (int i = arr.size(); i >= 2; i--)
        {
            int _max = arr[0];
            int index = 0;
            for (int j = 1; j < i; j++)
            {
                if (_max < arr[j])
                {
                    _max = arr[j];
                    index = j;
                }
            }
            // 说明需要调整
            if (index != i - 1)
            {
                if (index)
                {
                    reverse(arr.begin(), arr.begin() + index + 1);
                    res.push_back(index + 1);
                }
                reverse(arr.begin(), arr.begin() + i);

                res.push_back(i);
            }
        }
        return res;
    }
};