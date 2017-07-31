#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct st {
	int child;
	int weight;
	st(int c, int w) : child(c), weight(w) {
	}
};

vector<st> v[10001];

int ans = 0;
int dis[10001];

int bfs(int root) {
	if (v[root].size() == 0) return 0;

	int max = 0, smax = 0, temp;
	for (int i = 0; i < v[root].size(); i++) {
		temp = bfs(v[root][i].child) + v[root][i].weight;
		if (max < temp) {
			smax = max;
			max = temp;
		}
		else if (smax < temp) smax = temp;
	}

	dis[root] = max + smax;

	if (dis[root] > ans) ans = dis[root];

	return max;
}

int main() {

	int n; scanf("%d", &n);

	int node, c, w;
	for (int i = 0; i < n-1; i++) {
		scanf("%d", &node);
		scanf("%d", &c);
		scanf("%d", &w);

		v[node].push_back(st(c, w));
	}

	bfs(1);

	printf("%d", ans);
}
