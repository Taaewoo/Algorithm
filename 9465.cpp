#include <iostream>
#include <algorithm>
using namespace std;

int dp[100000][3];
int arr[100000][2];

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);

		
		for (int i = 0; i < n; i++) scanf("%d", &arr[i][0]);
		for (int i = 0; i < n; i++) scanf("%d", &arr[i][1]);

		dp[0][0] = 0;
		dp[0][1] = arr[0][0];
		dp[0][2] = arr[0][1];
		for (int i = 1; i <= n; i++) {
			dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]); //선택 안하기
			dp[i][1] = max(dp[i - 1][2], dp[i - 1][0]) + arr[i][0]; // 첫번째 행 선택
			dp[i][2] = max(dp[i - 1][1], dp[i - 1][0]) + arr[i][1]; // 두번째 행 선택
		}

		cout << max(max(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]) << endl;
	}
}
