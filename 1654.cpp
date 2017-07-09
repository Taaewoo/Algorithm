#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

int n;
long long ans=0;
int m;
long long arr[1000000];

void exist(){
	long long start=1, end=arr[n-1];

	while(start <= end){
		long long mid = (start+end)/2;
		
		int total=0;
		for(int i=0; i<n; i++) total += arr[i]/mid;

		if( total >= m ){
			if( ans < mid ) ans = mid;
			start=mid+1;
		}
		else if( total < m ) end=mid-1;
	}
}

int main(){

	scanf("%d %d", &n, &m);

	for(int i=0; i<n; i++) scanf("%lld", &arr[i]);

	sort(arr, arr+n);
	
	exist();

	printf("%lld", ans);
}
