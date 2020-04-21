#include <iostream>
using namespace std;

int main()
{
    int x, y, z;
    while (cin >> x >> y >> z)
    {
        int sum = x * 3 + 2 * y + z * 6;
        if (sum < 60)
            cout << "Exam was too hard.\n";
        else
        {
            cout << "I passed the exam.\n";
        }
        cout << sum << endl;
    }
}