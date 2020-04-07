#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

typedef pair<int, int> P;

const int max_v = 500;
const int INF = 987654321;	

int main() {
	int n, m; scanf("%d %d", &n, &m);

	vector<P> adj[max_v];
	for (int i = 0; i < m; i++) {
		int u, v, w; scanf("%d %d %d", &u, &v, &w);
		adj[u - 1].push_back(P(v - 1, w));
	}

	int dist[max_v];
	fill(dist, dist + max_v, INF);
	bool minus = false;
	dist[0] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++){
			for (auto &p : adj[j]) {
				int next = p.first, d = p.second;
				if (dist[next] > dist[j] + d && dist[j] != INF) {
					dist[next] = dist[j] + d;
					if (i == n - 1) minus = true;
				}
			}
		}
	}
	if (minus) printf("-1");
	else 
		for (int i = 1; i < n; i++) printf("%d\n", dist[i] != INF ? dist[i] : -1);
}
