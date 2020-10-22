#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isLongPressedName(string name, string typed)
    {
        int l = 0, r = 0, nl = name.length(), tl = typed.length();
        while (l < nl && r < tl)
        {
            if (name[l] != typed[r])
            {
                return false;
            }
            //相等情况
            else
            {
                if (r + 1 < tl && name[l] == typed[r + 1])
                {
                    if (l + 1 < nl && name[l + 1] != typed[r + 1] || l + 1 == nl)
                    {
                        r++;
                        continue;
                    }
                }
                l++;
                r++;
            }
        }
        return l == nl && r == tl;
    }
};

int main()
{
    string n = "vtkgn", t = "vttkgnn";
    Solution s;
    cout << s.isLongPressedName(n, t);
    system("pause");
}
