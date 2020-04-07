#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int n; scanf("%d", &n);

	int arr[1001][3];
	int dp[1001][3];

	for (int i = 0; i < n; i++) scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);

	dp[0][0] = arr[0][0]; dp[0][1] = arr[0][1]; dp[0][2] = arr[0][2];
	

	for (int i = 1; i < n; i++) {
		dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + arr[i][0];
		dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + arr[i][1];
		dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + arr[i][2];
	}

	cout << min( min(dp[n-1][0], dp[n-1][1]), dp[n-1][2]);
}
