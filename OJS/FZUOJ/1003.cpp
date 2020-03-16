#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool judge[12];

bool Judge(string strs[3], char point)
{
    int tag = 0; //为0 1 重 2轻
    char ch;
    for (int j = 0; j < 3; j++)
    {
        ch = strs[j][10];
        if (ch != 'e')
            for (int i = 0; i < 9; i++)
            {
                if (i != 4)
                {
                    if (strs[j][i] == point)
                    {
                        int temp;
                        if (i < 4)
                        {
                            if (ch = 'u')
                                temp = 1;
                            else
                                temp = 2;
                        }
                        else
                        {
                            if (ch = 'u')
                                temp = 2;
                            else
                                temp = 1;
                        }
                        if (tag == 0)
                            tag = temp;
                        else if (tag == temp)
                            return true;
                        else
                            return false;
                        break;
                    }
                }
            }
    }
    return tag;
}

void AddTrue(string str)
{
    for (int i = 0; i < 4; i++)
    {
        judge[str[i] - 'A'] = true;
    }
    for (int i = 4; i < 9; i++)
    {
        judge[str[i] - 'A'] = true;
    }
}

//明天开始暴力枚举
int main()
{
    int n;
    cin >> n;
    getchar();
    string strs[3];
    while (n--)
    {
        memset(judge, false, sizeof(judge));
        getline(cin, strs[0]);
        getline(cin, strs[1]);
        getline(cin, strs[2]);
        for (int i = 0; i < 3; i++)
        {
            if (strs[i][10] == 'e')
                AddTrue(strs[i]);
        }
        for (int i = 0; i < 12; i++)
        {
            if (!judge[i])
            {
                if (Judge(strs, 'A' + i))
                {
                    cout << (char)('A' + i) << " is the counterfeit coin and it is light." << endl;
                    break;
                }
            }
        }
    }
    //system("pause");
}