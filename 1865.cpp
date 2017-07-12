#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

typedef pair<int, int> P;

const int max_v = 501;
const int INF = 987654321;	

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, m, w; scanf("%d %d %d", &n, &m, &w);

		vector<P> adj[max_v];
		for (int i = 0; i < m; i++) {
			int u, v, w; scanf("%d %d %d", &u, &v, &w);
			adj[u].push_back(P(v, w));
			adj[v].push_back(P(u, w));
		}

		for (int i = 0; i < w; i++) {
			int u, v, w; scanf("%d %d %d", &u, &v, &w);
			adj[u].push_back(P(v, -w));
		}

		int dist[max_v];
		fill(dist, dist + max_v, INF);
		bool minus = false;
		dist[1] = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (auto &p : adj[j]) {
					int next = p.first, d = p.second;
					if (dist[next] > dist[j] + d && dist[j] != INF) {
						dist[next] = dist[j] + d;
						if (i == n) minus = true;
					}
				}
			}
		}
		if (minus) printf("YES\n");
		else printf("NO\n");
	}
}
