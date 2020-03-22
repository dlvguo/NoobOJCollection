#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int num[100001] = {0, 1}, index = 1;
int num2[100001] = {0, 0}, count = 0;
//矩阵连乘
void Figure(vector<int> &v)
{
    int _num = 1;
    int _index = index;
    if (count % 2)
    {
        for (int j = 1; j <= index; j++)
        {
            int dig = 0;
            int vcount = 0;
            for (int i = v.size() - 1; i >= 0; i--, vcount++)
            {
                int temp = v[i] * num[j] + dig + num2[vcount + j];
                dig = temp / 10;
                temp %= 10;
                num2[vcount + j] = temp;
            }
            while (dig)
            {
                int temp = num2[vcount + j] + 1;
                dig = temp / 10;
                temp %= 10;
                num2[vcount + j] = temp;
                if (vcount + j > _index)
                    _index = vcount + j;
            }
        }
    }
    else
    {
        for (int j = 1; j <= index; j++)
        {
            int dig = 0;
            int vcount = 0;
            for (int i = v.size() - 1; i >= 0; i--, vcount++)
            {
                int temp = v[i] * num2[j] + dig + num[vcount + j];
                dig = temp / 10;
                temp %= 10;
                num[vcount + j] = temp;
            }
            while (dig)
            {
                int temp = num[vcount + j] + 1;
                dig = temp / 10;
                temp %= 10;
                num[vcount + j] = temp;
                if (vcount + j > _index)
                    _index = vcount + j;
            }
        }
    }
}

int main()
{

    string str;
    getline(cin, str);

    vector<int> v;
    int count = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != '*')
        {
            v.push_back(str[i] - '0');
        }
        else
        {
            count++;
            Figure(v);
        }
    }
    count++;
    Figure(v);

    if (count % 2 == 1)
    {
        for (int i = index; i >= 1; i--)
            cout << num2[i] << endl;
    }
    else
    {
        for (int i = index; i >= 1; i--)
        {
            cout << num[i];
        }
    }
    cout << endl;

    system("pause");
}