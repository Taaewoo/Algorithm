#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <utility>
using namespace std;

const int Max_V = 1000;
const long INF = 10000000000;
typedef pair<int, int> P;

int main() {
	int n, m; scanf("%d %d", &n, &m);

	vector<P> adj[Max_V];

	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u - 1].push_back(P(v - 1, w));
		adj[v - 1].push_back(P(u - 1, w));
	}

	int a, b; scanf("%d %d", &a, &b);

	int s[5] = { 0,a-1,b-1,0,a-1 }, e[5] = { a-1,b-1,n - 1,b-1,n-1 };

	long ans[5];

	for (int t = 0; t < 5; t++) {
		long dist[Max_V];
		fill(dist, dist + Max_V, INF);
		bool visit[Max_V] = { 0 };

		priority_queue<P, vector<P>, greater<P>> PQ;

		dist[s[t]] = 0;
		PQ.push(P(0, s[t]));
		while (!PQ.empty()) {
			int cur;
			do {
				cur = PQ.top().second;
				PQ.pop();
			} while (!PQ.empty() && visit[cur]);

			if (visit[cur]) break;

			visit[cur] = true;

			for (auto &p : adj[cur]) {
				int next = p.first, d = p.second;
				if (dist[next] > dist[cur] + d) {
					dist[next] = dist[cur] + d;
					PQ.push(P(dist[next], next));
				}
			}
		}
		ans[t] = dist[e[t]];
	}

	long tot;
	tot =  min(ans[0] + ans[1] + ans[2], ans[3] + ans[4] + ans[1]);
	printf("%lld", tot >= INF ? -1 : tot);
}
