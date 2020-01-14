#include <iostream>
#include <cstring>
using namespace std;

int Figure(char *s, int &low, int &high, int len);

char *longestPalindrome(char *s)
{

    int len = strlen(s);
    if (!len) //空直接返回
        return s;
    int max = 0;
    int low = len / 2, high = len / 2;
    int flag = 0;//用于剪枝 
    int maxindex1 = 0, maxindex2 = 0;
    while (low >= 0 || high < len)
    {
        flag = 0;
        //先遍历左 剪枝
        if ((low+1 )* 2 < max)
        {
            flag++;
        }
        else
        {
            //从low左右开始
            int low1 = low - 1, high1 = low + 1;            
            int temp = Figure(s,low1,high1,len);
            //遍历aba型
            if (low1 <= high1 && temp > max)
            {
                max = temp;
                maxindex1 = low1;
                maxindex2 = high1;
            }

            //遍历abba型
            low1 = low-1, high1 = low;
            temp =Figure(s,low1,high1,len);
            if (low1 <= high1 && temp > max)
            {
                max = temp;
                maxindex1 = low1;
                maxindex2 = high1;
            }
        }
        low--;

        //遍历右 剪枝
        if ((len - high+1) * 2 < max)
        {
            flag++;
        }
        else
        {
            //从low左右开始
            int low1 = high - 1, high1 = high + 1;
            
            int temp =Figure(s,low1,high1,len);
            if (low1 < high1 && temp > max)
            {
                max = temp;
                maxindex1 = low1;
                maxindex2 = high1;
            }
            low1 = high, high1 = high + 1;
            
            temp = Figure(s,low1,high1,len);
            if (low1 < high1 && temp >= max)
            {
                max = temp;
                maxindex1 = low1;
                maxindex2 = high1;
            }
        }
        high++;
    }
    len = maxindex2 - maxindex1 + 2;
    char *str = (char *)malloc(len);
    for (int i = maxindex1, k = 0; i <= maxindex2; i++, k++)
    {
        str[k] = s[i];
    }
    str[len - 1] = '\0';
    return str;
}



int Figure(char *s, int &low, int &high, int len)
{
    while (low >= 0 && high <= len - 1 && s[low] == s[high])
    {
        low--;
        high++;
    }
    low++;
    high--;
    return (high - low) / 2 + 1;
}

int main()
{
    char *s = "babaddtattarrattatddetartrateedredividerb";
    cout << longestPalindrome(s);
}