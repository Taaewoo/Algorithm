#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int arr[100001];

int main() {
	int n; scanf("%d", &n);

	priority_queue<int,vector<int>,greater<int>> q;

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		q.push(arr[i]);
	}

	int ans = 0,temp1,temp2;
	while (q.size()>1) {
		temp1 = q.top(); q.pop();
		temp2 = q.top(); q.pop();
		
		ans += temp1 + temp2;

		q.push(temp1 + temp2);
	}
	printf("%d", ans);
}
