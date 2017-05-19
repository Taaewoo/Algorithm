#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int n, num, first, second;
int arr[21];
int cache[21][21][21];

int move(int index, int f, int s) {
	if (index == num) return 0;

	int& ret = cache[f][s][index];

	if (ret != -1) return ret;

	return ret = min(move(index + 1, arr[index], s) + abs(f - arr[index]), move(index + 1, f, arr[index]) + abs(s - arr[index]));
}

int main() {
	memset(cache, -1, sizeof(cache));

	cin >> n >> first >> second >> num;
	
	for (int i = 0; i < num; i++) scanf("%d", &arr[i]);

	cout << move(0, first, second);
}
