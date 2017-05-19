#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
int arr[500000];
int mArr[500000];

int binary(int x) {
	int start = 0;
	int end = n - 1;

	while (start <= end) {
		int mid = (start + end) / 2;
		if (arr[mid] < x) start = mid + 1;
		else if (arr[mid] > x) end = mid - 1;
		else return 1;
	}
	return 0;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	sort(arr, arr + n);

	cin >> m;
	for (int i = 0; i < m; i++) scanf("%d", &mArr[i]);
	for (int i = 0; i < m; i++) printf("%d ", binary(mArr[i]));
}
