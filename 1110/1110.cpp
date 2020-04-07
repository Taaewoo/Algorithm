#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <deque>
#include <queue>
#include <functional>
using namespace std;

int main() {
	int n; cin >> n;

	int N = n; int cnt = 0;

	do {
		int temp1, temp2;

		temp1 = (n % 10 + n / 10) % 10;
		temp2 = n % 10;

		n = temp1 + temp2*10;

		cnt++;
	} while (N != n);

	cout << cnt;
}
