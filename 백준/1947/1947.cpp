#include <iostream>
using namespace std;

long long arr[1000000];

int main()
{
	int n; scanf("%d", &n);

	arr[1] = 0;
	arr[2] = 1;
	for (int i = 3; i <= n; i++) arr[i] = (i - 1)*(arr[i - 1] + arr[i - 2]) % 1000000000;
	cout << arr[n];
}
