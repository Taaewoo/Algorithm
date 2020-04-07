#include <stdio.h>
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int n, k, ans;
queue<int> q;
int visit[100001];

int main() {
	memset(visit, -1, sizeof(visit));

	scanf("%d %d", &n,&k);

	q.push(n); visit[n] = 0;

	int x;
	while (!q.empty()) {
		x = q.front(); q.pop();
		
		if (x == k) ans = visit[x];

		if (x - 1 >= 0 && visit[x - 1] == -1) {
			visit[x - 1] = visit[x] + 1;
			q.push(x - 1);
		}
		if (x + 1 <= 100000 && visit[x + 1] == -1) {
			visit[x + 1] = visit[x] + 1;
			q.push(x + 1);
		}
		if (x * 2 <= 100000 && visit[x * 2] == -1) {
			visit[x * 2] = visit[x] + 1;
			q.push(x * 2);
		}
	}

	printf("%d", ans);
}
