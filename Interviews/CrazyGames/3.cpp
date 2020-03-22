#include <iostream>
#include <vector>
using namespace std;

int map[10001][10001] = {0};
int visit[10001][10001] = {0};
vector<int> points;
vector<int> gos;
vector<int> paths;

int main()
{
    string str;
    getline(cin, str);
    int first = 0, second;
    int i;
    for (i = 0; i < str.size() && str[i] != '|'; i++)
    {
        first = str[i] - '0';
        second = str[i + 2] - '0';
        map[first][second] = 1;
        map[second][first] = 1;
        i += 3;
    }
    for (i += 1; i < str.size() && str[i] != '|'; i++)
    {
        if (str[i] != ',')
        {
            gos.push_back(str[i] - '0');
        }
    }
    for (i += 1; i < str.size(); i++)
    {
        if (str[i] != ',')
        {
            points.push_back(str[i] - '0');
        }
    }
}