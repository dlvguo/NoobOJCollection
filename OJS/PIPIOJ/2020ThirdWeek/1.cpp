#include <iostream>
#include <cstring>
#include<vector>
#include<algorithm>
using namespace std;


int nums[11] = {0};
int visit[11] = {0};
long long _num;
vector<int> numsV;

void dfs(int nowcount, long long num, int count)
{
    if (nowcount == count)
    {
        if (num <= _num)
            return;
        if (num % _num == 0)
        {
            numsV.push_back(num);
        }
    }
    for (int i = 0; i < count; i++)
    {
        if (visit[i])
            continue;
        visit[i] = 1;
        dfs(nowcount + 1, num * 10 + nums[i], count);
        visit[i] = 0;
    }
}

int main()
{
    int t, count = 0;
    cin >> t;
    long long temp;
    while (t--)
    {
        numsV.clear();
        memset(nums, 0, sizeof(nums));
        memset(visit, 0, sizeof(visit));
        cin >> _num;
        temp = _num;
        count = 0;
        //计算数量
        while (temp)
        {
            nums[count++] = temp % 10;
            temp /= 10;
        }
        for (int i = 0; i < count / 2; ++i)
        {
            temp = nums[count - i - 1];
            nums[count - i - 1] = nums[i];
            nums[i] = temp;
        }

        dfs(0, 0, count);
        if(!numsV.size())
        cout<<"Impossible"<<endl;
        else{
            temp=0;
            sort(numsV.begin(),numsV.end());
            for (int i = 0; i <numsV.size(); i++)
            {
                if(!temp)
                    temp=numsV[i];
                else if(numsV[i]==temp)
                    continue;
                cout<<numsV[i]<<endl;
            }
            
        }
    }
}