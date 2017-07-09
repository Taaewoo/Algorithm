#include <stdio.h>
using namespace std;

int main(){//100!의 경우 1*2*...*100 이므로 5의 갯수 20개 + 5가 2번 들어간 숫자 갯수 = 24
	int n,count=0;

	scanf("%d", &n);

	for(int i=5; i<=n; i*=5)
		count += n/i;

	printf("%d", count);
}
