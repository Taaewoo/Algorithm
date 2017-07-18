#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int num[100000];
int check[100000];

void exist(int x){
	int start=0, end=n-1;

	while(1){
		if(start+1 == end || start==end){
			if(num[start] == x || num[end] == x){
				printf("1\n");
				return;
			}
			else{
				printf("0\n");
				return;
			}
		}

		int mid = (start+end)/2;
		if( num[mid] == x ){
			printf("1\n");
			return;
		}
		else if( num[mid] < x ) start=mid+1;
		else if( num[mid] > x ) end=mid-1;
	}
}

int main(){

	scanf("%d", &n);

	for(int i=0; i<n; i++) scanf("%d", &num[i]);

	scanf("%d", &m);

	for(int i=0; i<m; i++) scanf("%d", &check[i]);

	sort(num, num+n);

	for(int i=0; i<m; i++) exist(check[i]);
}
