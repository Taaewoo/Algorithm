#include <iostream>
#include <string.h>
#include <vector>
#include <stack>
using namespace std;

int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

int main() {
	int t; cin >> t;

	while (t--) {
		int X, Y, n; scanf("%d %d %d", &X, &Y, &n);
		
		int arr[51][51];
		bool visit[51][51];
		vector<pair<int, int>> v;

		memset(arr, 0, sizeof(arr));
		memset(visit, 1, sizeof(visit));

		for (int i = 0; i < n; i++) {
			int x, y; scanf("%d %d", &x, &y);
			v.push_back(make_pair(x, y));
			arr[x][y] = 1;
		}

		int ans = 0;
		for (int i = 0; i < v.size(); i++) {
			if (!visit[v[i].first][v[i].second]) continue;

			stack<pair<int,int>> s;
			s.push(v[i]);
			while (!s.empty()) {
				int curX = s.top().first, curY = s.top().second; s.pop();

				visit[curX][curY] = false;

				for (int j = 0; j < 4; j++) {
					int neX = curX + dir[j][0], neY = curY + dir[j][1];
					if (neX >= 0 && neX <= X && neY >= 0 && neY <= Y
						 && arr[neX][neY] == 1 && visit[neX][neY] == true) {
						s.push(make_pair(neX, neY));
					}
				}
			}
			ans++;
		}

		cout << ans << endl;
	}
}
