#include <iostream>
#include <algorithm>
using namespace std;

const int max_v = 101;
const int INF = 987654321;

int main() {
	int n; scanf("%d", &n);
	int m; scanf("%d", &m);

	int cost[max_v][max_v];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cost[i][j] = i == j ? 0 : INF;
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		cost[a][b] = min(cost[a][b],c);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", cost[i][j]);
		}
		printf("\n");
	}
	
}
