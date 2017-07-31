#include <iostream>

int main(){
	int n,m,s=0;
	int total=0, min;

	scanf("%d", &m);

	scanf("%d", &n);

	while(1){
		if( (s+1)*(s+1) >= m ) break;
		s++;
	}

	for(int i=s+1; i*i<=n; i++){
		if( i == s+1 ) min = i*i;
		total += i*i;
	}

	if( total == 0 ) printf("-1");
	else printf("%d\n%d", total,min);
}
