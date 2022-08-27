#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, k; scanf("%d %d", &n, &k);

	int dp[10001];
	int coin[10001];

	for (int i = 0; i < n; i++) scanf("%d", &coin[i]);

	fill(dp, dp + 10001, 100000);

	sort(coin, coin + n);

	dp[0] = 0;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < n; j++) { 
			if (i - coin[j] < 0) break; // 코인 종류가 현재 숫자보다 크면 break

			//현재 코인을 더하기 전에 숫자가 가능해야 하고, 최소값 계산
			if (dp[i - coin[j]] != 100000) dp[i] = min(dp[i], dp[i - coin[j]] + 1);
		}
	}

	cout << (dp[k] == 100000 ? -1 : dp[k]);
}
