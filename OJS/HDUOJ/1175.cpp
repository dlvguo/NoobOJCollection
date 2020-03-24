#include<iostream>
#include<cstring>
using namespace std;
#define Max 1003
int n, m, map[Max][Max], visit[Max][Max];
int x1, x2, y1, y2;
bool flag;

void dfs(int x, int y, int k, int z) {
	if (flag || k > 2 || x < 1 || y < 1 || x > n || y > m )
		return;
	if (x == x2&&y == y2) {
		flag = true;
		return;
	}
	if (k==2)
	 if(!(z==1&&x>x2&&y==y2||z==2&&x<x2&&y==y2||z==3&&x==x2&&y>y2||z==4&&x==x2&&y<y2))
		return;	
	if(map[x][y]|| visit[x][y])
     return ;
	visit[x][y] = 1;
	if (z == 1) {
		dfs(x - 1, y, k, 1);
		dfs(x + 1, y, k + 1, 2);
		dfs(x, y - 1, k + 1, 3);
		dfs(x, y + 1, k + 1, 4);
	}
	else if (z == 2) {
		dfs(x - 1, y, k + 1, 1);
		dfs(x + 1, y, k, 2);
		dfs(x, y - 1, k + 1, 3);
		dfs(x, y + 1, k + 1, 4);
	}
	else if (z == 3) {
		dfs(x - 1, y, k + 1, 1);
		dfs(x + 1, y, k + 1, 2);
		dfs(x, y - 1, k, 3);
		dfs(x, y + 1, k + 1, 4);
	}
	else {
		dfs(x - 1, y, k + 1, 1);
		dfs(x + 1, y, k + 1, 2);
		dfs(x, y - 1, k + 1, 3);
		dfs(x, y + 1, k, 4);
	}
	visit[x][y] = 0;
}


int main() {
	int q;
	while (cin >> n >> m) {
		if (n == 0 && m == 0)
			break;
		for (int i = 1; i <=n; i++)
			for (int j = 1; j <=m; j++)
				cin >> map[i][j];
		cin >> q;
		while (q--)
		{
			cin >> x1 >> y1 >> x2 >> y2;
			flag = false;
			memset(visit, 0, sizeof(visit));
			if (x1 == x2&&y1 == y2 && map[x1][y1])
				cout << "NO" << endl;
			else if (map[x1][y1] == map[x2][y2] && map[x1][y1])
			{
				dfs(x1 - 1, y1, 0, 1);
				dfs(x1 + 1, y1, 0, 2);
				dfs(x1, y1 - 1, 0, 3);
				dfs(x1, y1 + 1, 0, 4);
				if (flag)
					cout << "YES" << endl;
				else
					cout << "NO" << endl;
			}
			else
				cout << "NO" << endl;
		}
	}
	return 0;
}
