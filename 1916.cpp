#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <utility>
using namespace std;

const int Max_V = 1000;
const int INF = 1000000000;
typedef pair<int, int> P;

int main() {
	int n, m; scanf("%d %d", &n, &m);

	vector<P> adj[Max_V];

	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u - 1].push_back(P(v-1, w));
	}

	int s, e;
	scanf("%d %d", &s, &e);
	s--; e--;

	int dist[Max_V];
	fill(dist, dist + Max_V, INF);
	bool visit[Max_V] = { 0 };

	priority_queue<P, vector<P>, greater<P>> PQ;

	dist[s] = 0;
	PQ.push(P(0, s));
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

	cout << dist[e];
}
