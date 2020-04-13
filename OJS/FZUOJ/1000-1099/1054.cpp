#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string str;
    getchar();
    while (n--)
    {
        getline(cin, str);
        for (int i = str.size()-1; i>=0; i--)
        {
            cout<<str[i];
        }
        cout<<endl;
    }
}