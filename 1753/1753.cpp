#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

vector<pair<int, int>> vec[30001];	

int dis[20001];
bool visit[20001];

int main() {
	int n, e, start;
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> q;

	scanf("%d %d", &n, &e);
	scanf("%d", &start);

	int u, v, w;
	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &u, &v, &w);
		vec[u].push_back(make_pair(v, w));
	}

	for (int i = 1; i <= n; i++) dis[i] = 1000000000;

	dis[start] = 0;
	q.push(make_pair(0, start));

	pair<int, int> temp;
	while (!q.empty()) {
		temp = q.top();
		q.pop();
		int num = temp.second; //현재지점

		if (visit[num]) continue;

		visit[num] = true;

		for (int i = 0; i < vec[num].size(); i++) { // 해당지점의 목표
			int to = vec[num][i].first;

			if (dis[to] > dis[num] + vec[num][i].second) {
				dis[to] = dis[num] + vec[num][i].second;
				q.push(make_pair(dis[to],to));
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (dis[i] == 1000000000) printf("INF\n");
		else printf("%d\n", dis[i]);
	}

}
