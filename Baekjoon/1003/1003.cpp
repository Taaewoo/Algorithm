#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int t,n; scanf("%d", &t);
	pair<int, int> dp[41];

	dp[0].first = 1;
	dp[0].second = 0;
	dp[1].first = 0;
	dp[1].second = 1;

	while (t--) {
		scanf("%d", &n);

		for (int i = 2; i <= n; i++) {
			dp[i].first = dp[i - 1].first + dp[i - 2].first;
			dp[i].second = dp[i - 1].second + dp[i - 2].second;
		}
		printf("%d %d\n", dp[n].first, dp[n].second);
	}
}
