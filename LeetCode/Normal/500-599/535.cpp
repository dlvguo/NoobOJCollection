#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    unordered_map<int, string> dataBase;
    int id;

public:
    Solution()
    {
        id = 0;
    }

    string encode(string longUrl)
    {
        id++;
        dataBase[id] = longUrl;
        return string("http://tinyurl.com/") + to_string(id);
    }

    string decode(string shortUrl)
    {
        int p = shortUrl.rfind('/') + 1;
        int key = stoi(shortUrl.substr(p, int(shortUrl.size()) - p));
        return dataBase[key];
    }
};
