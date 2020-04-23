#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string str;
    //搞复杂化了 就是一个栈的应用
    while (cin >> str)
    {
        stack<char> s;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '(')
            {
                s.push(str[i]);
            }
            else
            {
                if (s.size() && s.top() == '(')
                {
                    s.pop();
                }
                else
                {
                    s.push(str[i]);
                }
            }
        }
        if (s.empty())
        {
            cout << str << endl;
        }
        else
        {
            string t;
            while (s.size())
            {
                t += s.top();
                s.pop();
            }
            int leftCount = 0, rightCount = 0;
            for (int i = t.size() - 1; i >= 0; i--)
            {
                if (t[i] == '(')
                    rightCount++;
                else
                    leftCount++;
                cout << t[i];
            }
            cout << endl;
            while (leftCount--)
            {
                cout << '(';
            }
            for (int i = t.size() - 1; i >= 0; i--)
            {
                cout << t[i];
            }
            while (rightCount--)
            {
                cout << ')';
            }
            cout << endl;
        }
    }
}