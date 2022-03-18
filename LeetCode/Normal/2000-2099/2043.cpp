#include <bits/stdc++.h>
using namespace std;
class Bank
{
public:
    vector<long long> b;
    Bank(vector<long long> &balance)
    {
        b.resize(balance.size() + 1);
        for (int i = 0; i < balance.size(); i++)
        {
            b[i + 1] = balance[i];
        }
    }

    bool transfer(int account1, int account2, long long money)
    {
        if (account1 >= b.size() || account2 >= b.size())
            return false;
        if (b[account1] >= money)
        {
            b[account1] -= money;
            b[account2] += money;
            return true;
        }
        return false;
    }

    bool deposit(int account, long long money)
    {
        if (account >= b.size())
            return false;
        b[account] += money;
        return true;
    }

    bool withdraw(int account, long long money)
    {
        if (account >= b.size())
            return false;

        if (b[account] >= money)
        {
            b[account] -= money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */