#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> P;

int dir[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };

int arr[1001][1001];
bool visit[1001][1001];

int main() {
	int n, m; scanf("%d %d", &n, &m);

	queue<pair<P, int>> q;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1) q.push(make_pair(P(i, j), 0));
		}
	}

	if (q.size() == n*m) {
		cout << 0;
		return 0;
	}

	int ans = 0;
	while (!q.empty()) {
		int curX = q.front().first.second, curY = q.front().first.first, curN = q.front().second;
		q.pop();
		ans = curN;
		visit[curY][curX] = true;

		for (int i = 0; i < 4; i++) {
			int nxtX = curX + dir[i][1], nxtY = curY + dir[i][0];
			if (nxtX < 0 || nxtX >= n || nxtY < 0 || nxtY >= m || arr[nxtY][nxtX] == 1 || arr[nxtY][nxtX] == -1 || visit[nxtY][nxtX]) continue;

			arr[nxtY][nxtX] = 1;
			q.push(make_pair(P(nxtY, nxtX), curN + 1));
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j] && arr[i][j] != -1) {
				cout << "-1";
				return 0;
			}
		}
	}

	cout << ans;
}
