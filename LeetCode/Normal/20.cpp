#include <iostream>
#include <bits/stdc++.h>
#include <cstring>
using namespace std;

bool isValid(char *s)
{
    int len = strlen(s);
    if (len % 2)
        return false;
    char *stack = (char *)malloc(sizeof(char) * (len / 2));
    int top = -1;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '}' || s[i] == ']' || s[i] == ')')
        {
            if (top == -1 || !(s[i] == (stack[top] + 1) || s[i] == (stack[top] + 2)))
            {
                free(stack);
                return false;
            }
            top--;
        }
        else
        {
            top++;
            if (top ==( len/2))
                return false;
            stack[top] = s[i];
        }
    }
    free(stack);
    if (top != -1)
        return false;
    return true;
}

int main()
{
    char *s = "(()(";
    isValid(s);
}