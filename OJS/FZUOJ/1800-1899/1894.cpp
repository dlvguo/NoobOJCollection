#include <iostream>
#include <deque>
#include <queue>
#include <string>
using namespace std;


int main()
{
    //维护一个最大队列
    int t;
    cin >> t;
    getchar();
    //注意字符串操作 string中含有空格+数字 为了加快可以用 scanf(%s%d)组合 因为scanf是读到‘ ’结束
    while (t--)
    {
        deque<int> dq;
        queue<int> q;
        string str;
        while (getline(cin, str))
        {
            if (str[0] == 'E')
                break;
            else if (str[0] == 'Q')
            {
                if (dq.size())
                    cout << q.front() << endl;
                else
                {
                    cout << -1 << endl;
                }
            }
            else if (str[0] == 'G')
            {
                if (q.size())
                {
                    if (q.front() == dq.front())
                        dq.pop_front();
                    q.pop();
                }
            }
            else if (str[0] == 'C')
            {
                int res = 0;
                for (int i = 0; i < str.size(); i++)
                {
                    if (str[i] >= '0' && str[i] <= '9')
                        res = res * 10 + str[i] - '0';
                    q.push(res);
                    //放入
                    while (dq.size() && res > dq.back())
                    {
                        dq.pop_back();
                    }
                    dq.push_back(res);
                }
            }
        }
    }
}