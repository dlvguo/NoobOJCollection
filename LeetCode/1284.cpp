#include <iostream>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

void Set(int &num, int n)
{
    num = num | (1 << n);
}

int minFlips(vector<vector<int>> &mat)
{
    int visit[512] = {0};
    int row = mat.size(), lie = mat[0].size();
    int num = 0, len = row * lie, ans = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < lie; j++)
        {
            num += (mat[i][j] << (i * lie + j));
        }
    }
    if (!num)
        return num;
    visit[num] = 1;
    queue<int> numQ;
    numQ.push(num);
    while (!numQ.empty())
    {
        ans++;
        int l = numQ.size();
        while (l--)
        {
            num = numQ.front();
            numQ.pop();
            //还原下Map
            for (int i = 0; i < len; i++)
            {
                int num0 = num;
                num0 ^= (1 << i);
                if (i + lie < len)
                    num0 ^= (1 << (i + lie));
                if (i - lie >= 0)
                    num0 ^= (1 << (i - lie));
                if (i - 1 >= 0 && (i - 1) / lie == i / lie)
                    num0 ^= (1 << (i - 1));
                if ((i + 1) / lie == i / lie)
                    num0 ^= (1 << (i + 1));
                if (num0 == 0)
                    return ans;
                if (visit[num0] == 0)
                {
                    visit[num0] = 1;
                    numQ.push(num0);
                }
            }
        }
    }
    return -1;
}

int main()
{
}