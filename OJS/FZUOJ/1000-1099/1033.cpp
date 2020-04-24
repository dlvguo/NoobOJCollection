#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t;
	cin >> t;
	string df = "<default>";
	for (int ans = 1; ans <= t; ans++)
	{
		string str;
		cin >> str;
		string path, protocol, host, port;
		int index = 0;
		for (index = 0; index < str.size(); index++)
		{
			if (str[index] == ':')
			{
				index += 3;
				break;
			}
			protocol += str[index];
		}
		for (; index < str.size(); index++)
		{
			if (str[index] == ':' || str[index] == '/') {
				break;
			}
			host += str[index];
		}
		if (index < str.size() && str[index] == ':') {
			for (index += 1; index < str.size(); index++)
			{
				if (str[index] == '/') {
					break;
				}
				port += str[index];
			}
		}
		if (index < str.size() && str[index] == '/') {
			for (index += 1; index < str.size(); index++)
			{

				path += str[index];
			}
		}

		cout << "URL #" << ans << endl;
		cout << "Protocol = " << protocol << endl;
		cout << "Host     = " << host << endl;
		cout << "Port     = ";
		if (port.size() == 0)
		{
			cout << df << endl;
		}
		else
			cout << port << endl;
		cout << "Path     = ";
		if (path.size() == 0)
		{
			cout << df << endl << endl;
		}
		else
			cout << path << endl << endl;
	}
}