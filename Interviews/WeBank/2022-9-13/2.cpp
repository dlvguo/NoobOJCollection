#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main()
{
    LL n;
    cin >> n;
    while (n--)
    {
        LL a, b;
        cin >> a >> b;
        if (a == b)
        {
            cout << 0 << endl;
            continue;
        }
        queue<LL> q;
        unordered_set<LL> uset;
        q.push(a);
        uset.insert(a);
        LL ans = 0, cc = 0;
        bool tag = false;
        while (q.size() && !tag)
        {
            LL count = q.size();
            ans++;
            cc += count;
            while (count--)
            {
                LL num = q.front();
                q.pop();

                // *2 方法
                LL num1 = num * 2;
                if (num1 == b)
                {
                    tag = true;
                    break;
                }
                if (num1 > 0 && uset.find(num1) == uset.end())
                {
                    uset.emplace(num1);
                    q.push(num1);
                }

                //*8 方法
                num1 = num * 8;
                if (num1 == b)
                {
                    tag = true;
                    break;
                }
                if (num1 > 0 && uset.find(num1) == uset.end())
                {
                    uset.emplace(num1);
                    q.push(num1);
                }

                //*4 方法
                num1 = num * 4;
                if (num1 == b)
                {
                    tag = true;
                    break;
                }
                if (num1 > 0 && uset.find(num1) == uset.end())
                {
                    uset.emplace(num1);
                    q.push(num1);
                }

                // /2方法
                if (num % 2 == 0)
                {
                    num1 = num / 2;
                    if (num1 == b)
                    {
                        tag = true;
                        break;
                    }
                    if (uset.find(num1) == uset.end())
                    {
                        uset.emplace(num1);
                        q.push(num1);
                    }

                    num1 = num * 4;
                    if (num1 == b)
                    {
                        tag = true;
                        break;
                    }
                    if (uset.find(num1) == uset.end())
                    {
                        uset.emplace(num1);
                        q.push(num1);
                    }
                }

                // /4方法
                if (num % 4 == 0)
                {
                    num1 = num / 4;
                    if (num1 == b)
                    {
                        tag = true;
                        break;
                    }
                    if (uset.find(num1) == uset.end())
                    {
                        uset.emplace(num1);
                        q.push(num1);
                    }

                    num1 = num * 4;
                    if (num1 == b)
                    {
                        tag = true;
                        break;
                    }
                    if (uset.find(num1) == uset.end())
                    {
                        uset.emplace(num1);
                        q.push(num1);
                    }
                }

                // /8方法
                if (num % 8 == 0)
                {
                    num1 = num / 8;
                    if (num1 == b)
                    {
                        tag = true;
                        break;
                    }
                    if (uset.find(num1) == uset.end())
                    {
                        uset.emplace(num1);
                        q.push(num1);
                    }

                    num1 = num * 4;
                    if (num1 == b)
                    {
                        tag = true;
                        break;
                    }
                    if (uset.find(num1) == uset.end())
                    {
                        uset.emplace(num1);
                        q.push(num1);
                    }
                }
            }
            if (cc > 50000000)
            {
                break;
            }
        }
        if (!tag)
            ans = -1;
        cout << ans << endl;
    }
}