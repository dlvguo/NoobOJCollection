// PQJ-3278.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int N, K, visit[111000];
struct node {
	long long  sum;
	long long  cont;
}start;

void bfs() {
	int i;
	long long t;
	node first, next;
	queue<node>q;
	q.push(start);

	while (!q.empty()) {
		first = q.front();
		q.pop();
		if (first.sum * 2 - K == 0 || first.sum + 1 - K == 0 || first.sum - 1 - K == 0) {
			cout << first.cont + 1 << endl;
			return;
		}
		for (i = 0; i<3; i++) {
			if (!i)
				t = first.sum + 1;
			else if (i == 1)
				t = first.sum - 1;
			else
				t = first.sum * 2;
			if ( t > 100000 || t<0)
				continue;
			if (!visit[t]) {
				visit[t] = 1;
				next.sum = t;
				next.cont = first.cont + 1;
				q.push(next);
			}
		}
	}
	return;
}
int main()
{
	while (cin >> N >> K) {
		if (N>=K)
			cout << N - K << endl;
		else {
			memset(visit, 0, sizeof(visit));
			start.cont = 0;
			start.sum = N;
			visit[N] = 1;
			bfs();
		}
	}
	return 0;
}

