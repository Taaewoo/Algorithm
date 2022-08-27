#include <iostream>
using namespace std;

int gcd(int x, int y) {
	if (y == 0) return x;
	else return gcd(y, x%y);
}

int main() {
	int t; cin >> t;

	while (t--) {
		int a, b; scanf("%d %d", &a, &b);

		int g = gcd(a, b);

		printf("%d\n", g*(a / g)*(b / g));
	}
}
