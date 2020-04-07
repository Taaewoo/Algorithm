#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n; scanf("%d", &n);

	int arr[301];
	int dp[301][3];

	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);

	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[0][2] = 0;
	dp[1][1] = arr[1];
	dp[1][2] = 0;
	for (int i = 2; i <= n; i++) {
		dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + arr[i];
		dp[i][2] = dp[i - 1][1] + arr[i];
	}	
	cout << max(dp[n][1], dp[n][2]);
}
