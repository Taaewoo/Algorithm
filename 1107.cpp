#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ch, n;
bool but[10];

int main() {
	cin >> ch;
	cin >> n;
	
	int input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		but[input] = true;
	}

	int ans = abs(ch - 100);

	for (int i = 1000000; i >= 0; i--) {
		int temp = i, cnt = 0;
		bool flag = true;
		if (temp == 0) {
			cnt = 1;
			if(but[0]) flag = false;
		}
		while (temp) { 
			if (but[temp % 10]) {
				flag = false;
				break;
			}
			temp /= 10;
			cnt++;
		}
		if (!flag) continue;

		ans = min(ans, abs(ch - i) + cnt);
	}

	cout << ans;
}
