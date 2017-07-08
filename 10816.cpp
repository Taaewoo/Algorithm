#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int mArr[500001];
int n, m;

int main() {
	scanf("%d", &n);

	vector<int> v;

	int temp;
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		v.push_back(temp);
	}

	scanf("%d", &m);

	sort(v.begin(), v.end());

	for (int i = 0; i < m; i++) {
		scanf("%d", &mArr[i]);

		vector<int>::iterator low, up;
		low = lower_bound(v.begin(), v.end(), mArr[i]);
		
		if (*low != mArr[i]) {
			printf("0 ");
			continue;
		}

		up = upper_bound(v.begin(), v.end(), mArr[i]);
		
		cout << up - low << " ";
	}
}
