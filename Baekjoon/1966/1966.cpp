#include <iostream>
#include <deque>
#include <queue>
using namespace std;

int main() {
	int t; cin >> t;

	while (t--) {
		deque<pair<int,int>> d;
		priority_queue<int> p;
		int n, m, temp; cin >> n, cin >> m;
		bool check[100];

		for (int i = 0; i < 100; i++) check[i] = true;

		for (int i = 0; i < n; i++) {
			scanf("%d", &temp);
			d.push_back(make_pair(temp,i));
			p.push(temp);
		}

		int cnt = 0;
		while (1) {
			if (p.top() == d.front().first) {
				cnt++;
				if (d.front().second == m) break;
				p.pop();
				d.pop_front();
			}
			else {
				d.push_back(d.front());
				d.pop_front();
			}
		}
		cout << cnt << endl;
	}
}
