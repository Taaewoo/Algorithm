#include <iostream>
using namespace std;

long long dp[90][2];

int main() {
	int n; cin >> n;

	dp[1][0] = 0;
	dp[1][1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}
	cout << dp[n][0] + dp[n][1];
}
