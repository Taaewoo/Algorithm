#include <iostream>
#include <queue>
#include <string>
using namespace std;

typedef pair<int, int> P;

int dir[4][2] = { {1,0}, {0,1},{-1,0},{0,-1} };
int map[101][101];

int main() {
	int n, m; cin >> n >> m;

	string arr[101];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	
	queue<P> q;
	q.push(P(0, 0));
	map[0][0] = 1;
	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nxtX = curX + dir[i][0];
			int nxtY = curY + dir[i][1];
			if (nxtX < 0 || nxtX >= m || nxtY < 0 || nxtY >= n || map[nxtY][nxtX] != 1) continue;

			q.push(P(nxtX, nxtY));
			map[nxtY][nxtX] = map[curY][curX] + 1;
		}
	}

	cout << map[n - 1][m - 1];
}
