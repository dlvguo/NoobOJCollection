#include <iostream>
#include <string>
#include <deque>
using namespace std;

/*
    思路：使用STL双端队列做，分俩轮处理
    第一轮：先把括号的内序列处理，因为考虑括号可能叠加(())，于是每次碰见)就将一个括号内的序列找出来计算，并将结果放回序列中
    第二轮：因为括号都处理了，只要依次左乘即可
    注意：如果不合乎矩阵的行列跳出即可
*/

//矩阵
struct Matrix
{
    int row, lie;
};

int main()
{
    Matrix ms[28];

    int n, row, lie;
    char name;
    string xl; //存放输入序列
    while (cin >> n)
    {
        while (n--)
        {
            cin >> name >> row >> lie;
            ms[name - 'A'].row = row;
            ms[name - 'A'].lie = lie;
        }
        getchar();
        //获取序列
        getline(cin, xl);
        long long sum = 0;
        deque<char> dq;
        //第一轮 过滤括号
        for (int i = 0; i < xl.size(); i++)
        {
            if (xl[i] != ')')
            {
                dq.push_back(xl[i]);
            }
            //因为括号满足条件
            else
            {
                string s;
                while (dq.back() != '(')
                {
                    s += dq.back();
                    dq.pop_back();
                }
                dq.pop_back();

                //如(ABC) 出队列的时候的时候是CBA
                //于是后往前乘 ABC
                for (int j = s.size() - 1; j > 0; j--)
                {
                    int m1 = s[j] - 'A';     //第一个矩阵
                    int m2 = s[j - 1] - 'A'; //第二个矩阵
                    if (ms[m1].lie != ms[m2].row)
                    {
                        //不符合矩阵规则标记
                        sum = -1;
                        break;
                    }
                    sum += ms[m1].row * ms[m1].lie * ms[m2].lie;
                    //新的矩阵存放在第二个矩阵中迭代
                    ms[m2].row = ms[m1].row;
                }
                //乘完的矩阵放回序列
                dq.push_back(s[0]);
                if (sum == -1)
                    break;
            }
        }
        if (sum != -1)
        {
            //处理正常序列
            string s;
            while (dq.size())
            {
                s += dq.front();
                dq.pop_front();
            }
            for (int j = 0; j < s.size() - 1; j++)
            {
                int m1 = s[j] - 'A';
                int m2 = s[j + 1] - 'A';
                if (ms[m1].lie != ms[m2].row)
                {
                    sum = -1;
                    break;
                }
                sum += ms[m1].row * ms[m1].lie * ms[m2].lie;
                ms[m2].row = ms[m1].row;
            }
            if (sum != -1)
            {
                cout << sum << endl;
                continue;
            }
        }
        cout << "error" << endl;
    }
}