#include <iostream>
#include <algorithm>
using namespace std;

int uf[1000];

struct Edge {
	int u, v, w;
	Edge() : Edge(-1, -1, 0) {}
	Edge(int uu, int vv, int ww) : u(uu), v(vv), w(ww) {}
	bool operator <(const Edge& e)const { return w < e.w; }
};

Edge l[100001];

int find(int a) {
	if (uf[a] < 0) return a;
	return uf[a] = find(uf[a]);
}

bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	uf[b] = a;
	return true;
}

int main() {
	int n; scanf("%d", &n);
	int m; scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		l[i] = Edge(u - 1, v - 1, w);
	}

	sort(l, l + m);

	fill(uf, uf + n, -1);

	int ans = 0, cnt = 0;;
	for (int i = 0; i < m; i++) {
		if (merge(l[i].u, l[i].v)) {
			ans += l[i].w;
			cnt++;
			if (cnt == n - 1) break;
		}
	}
	cout << ans;
}
