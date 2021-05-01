#include <bits/stdc++.h>
using namespace std;

class Employee
{
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution
{
public:
    unordered_map<int, Employee *> mp;

    int dfs(int id)
    {
        Employee *employee = mp[id];
        int total = employee->importance;
        for (int subId : employee->subordinates)
        {
            total += dfs(subId);
        }
        return total;
    }

    int getImportance(vector<Employee *> employees, int id)
    {
        for (auto &employee : employees)
        {
            mp[employee->id] = employee;
        }
        return dfs(id);
    }
};
