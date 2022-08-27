#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n; cin >> n;

	int count=0;

	if (n < 100) count = n;
	else if (n >= 111) {
		for (int i = 111; i <= n; i++) {
			vector<int> v;

			int num = i;
			while (num / 10 > 0) {
				v.push_back(num % 10);
				num /= 10;
			}
			v.push_back(num);

			int temp = v[0] - v[1];
			for (int j = 1; j < v.size() - 1; j++) {
				if (v[j] - v[j + 1] != temp) break;
				if (j == v.size() - 2) count++;
			}
		}

		count += 99;
	}
	else count = 99;

	cout << count;
}
