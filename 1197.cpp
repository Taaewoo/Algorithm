#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <functional>
using namespace std;

int uf[10001];

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

struct Edge {
	int u, v, w;
	Edge() : Edge(-1, -1, 0) {}
	Edge(int u1, int v1, int w1) : u(u1), v(v1), w(w1) {}
	bool operator <(const Edge& O)const { return w < O.w; }
};

Edge e[100001];

int main() {
	int n, m; 
	scanf("%d", &n); scanf("%d", &m);
	
	int a, b, c;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		e[i] = Edge(a - 1, b - 1, c);
	}

	sort(e, e + m);

	int result = 0, cnt = 0;
	memset(uf, -1, sizeof(uf));

	for (int i = 0; ; i++) {
		if (merge(e[i].u, e[i].v)) {
			result += e[i].w;
			if (++cnt == n - 1) break;
		}
	}

	printf("%d\n", result);
}
