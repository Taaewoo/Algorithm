#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, k, d;

vector<int> line[302];
int c[302][302];
int f[302][302];
int pre[302];

void bfs() {
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int next : line[x]) {
			if (c[x][next] - f[x][next] > 0 && pre[next] == -1) {
				pre[next] = x;
				q.push(next);
				if (next == n + d + 1) return;
			}
		}
	}
}


int main() {
	scanf("%d %d %d", &n, &k, &d);

	for (int i = 1; i <= n; i++) {
		line[0].push_back(i);
		line[i].push_back(0);
		c[0][i] = k;
	}

	int temp;
	for (int i = 0; i < d; i++) {
		scanf("%d", &temp); //음식 접시 수
		line[n + i + 1].push_back(n + d + 1);
		line[n + d + 1].push_back(n + i + 1);
		c[n + i + 1][n + d + 1] = temp;
	}

	int food;
	for (int i = 0; i < n; i++) {
		scanf("%d", &food); // 한사람당 할 수 있는 음식 수
		int temp;
		for (int j = 0; j < food; j++) {
			scanf("%d", &temp); //음식 종류
			line[i + 1].push_back(n + temp);
			line[n + temp].push_back(i + 1);
			c[i + 1][n + temp] = 1;
		}
	}

	int ans = 0;
	while (1) {
		fill(pre, pre + 302, -1);
		bfs();

		if (pre[n + d + 1] == -1) break;

		int num = 1000000000;
		for (int i = n + d + 1; i > 0; i = pre[i])
			num = min(num, c[pre[i]][i] - f[pre[i]][i]);

		for (int i = n + d + 1; i > 0; i = pre[i]) {
			f[pre[i]][i] += num;
			f[i][pre[i]] -= num;
		}

		ans += num;
	}

	cout << ans;
}
