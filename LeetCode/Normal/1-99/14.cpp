#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    string str = "";
    int index = 0;
    char tempchar;
    if (strs.size() == 0)
        return str;

    while (true)
    {
        if (strs[0].length() < index + 1)
            return str;
        tempchar = strs[0][index];
        for (int i = 1; i < strs.size(); i++)
        {
            if (strs[i].length() < index + 1 || strs[i][index] != tempchar)
                return str;
        }
        index++;
        str += tempchar;

    }
    return str;
}

int main(){
    vector<string> strs={"flower","flow","flight"};
    cout<<longestCommonPrefix(strs);
    system("pause");
}