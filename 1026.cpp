#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

vector<int> a, b;
int n;

int main() {
	cin >> n;

	int temp;
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		a.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		b.push_back(temp);
	}

	sort(a.begin(), a.end(), greater<int>());
	sort(b.begin(), b.end(), less<int>());

	int ans = 0;
	for (int i = 0; i < n; i++) ans += a[i] * b[i];

	cout << ans;
}
