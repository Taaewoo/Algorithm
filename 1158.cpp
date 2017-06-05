#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <deque>
using namespace std;

int n, m;
int arr[10002];

int main() {
	memset(arr, 0, sizeof(arr));

	scanf("%d %d", &n,&m);

	printf("<");

	int cur = 0,cnt=0;
	while (1) {
		for (int i = 0; i < m; ) {
			cur++;
			if (cur == n+1) cur = 1;
			if (arr[cur] == 1) continue;

			i++;
		}
		arr[cur] = 1;
		printf("%d", cur);
		cnt++;
		if (cnt == n) break;
		printf(", ");
	}

	printf(">");
}
