#include <iostream>
using namespace std;

int main() {
	int n; scanf("%d", &n);

	int dp[1001];

	dp[0] = 1;
	dp[1] = 2;

	for (int i = 2; i < n; i++) 
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;

	cout << dp[n - 1];
}
