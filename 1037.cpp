#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;


int main(){
	int n;
	int arr[50];

	scanf("%d", &n);

	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);

	int temp;

	for (int i = 0; i < n-1; i++) {  
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {  
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	printf("%d",arr[0]*arr[n-1]);
}
