#include <iostream>
#include <string>
#include <cstring>
using namespace std;

char strs[3][3][15];

bool Judge(char point, int weight)
{
    int tag = 0, flag = 0; //用于标记
    char ch;
    for (int j = 0; j < 3; j++)
    {
        ch = strs[j][2][0];
        tag = 0;
        for (int i = 0; i < 2; i++)
        {
            for (int k = 0; strs[j][i][k] != '\0'; k++)
            {
                if (strs[j][i][k] == point)
                {
                    tag = 1;
                    flag = 1;
                    if (ch == 'e')
                        return false;
                    int temp;
                    if (i == 0)//出现在天平左边 1代表重 2代表轻
                    {
                        if (ch == 'u')
                            temp = 1;
                        else
                            temp = 2;
                    }
                    else //出现在天平右边
                    {
                        if (ch == 'u')
                            temp = 2;
                        else
                            temp = 1;
                    }
                    if (temp != weight)//与字符重量不符合
                        return false;
                }
            }
            if (tag)
                break;
        }
        if (!tag && ch != 'e')//如果目标字符不在重量不对称的天平情况下
            return false;
    }
    return flag;//flag=0说明未出现过
}

//终于A了
int main()
{
    int n;
    cin >> n;
    bool tag;
    string s[2] = {"heavy", "light"};
    while (n--)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                scanf("%s", strs[i][j]);
            }
        }
        for (int i = 0; i < 12; i++)
        {
            tag = false;
            for (int j = 0; j < 2; j++)
            {
                if (Judge('A' + i, j + 1)) //1重 2轻
                {
                    cout << (char)('A' + i) << " is the counterfeit coin and it is " << s[j] << '.' << endl;
                    tag = true;
                    break;
                }
            }
            if (tag)
                break;
        }
    }
    //system("pause");
}