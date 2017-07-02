#include <iostream>
#include <stdio.h>
using namespace std;

int n,result,arr[20],answer=0;

void calculate(int index,int total)
{
	total += arr[index];

	if(total == result) answer++;

	if(index == n-1) return;
	else
	{
		for(int i=index+1; i<n; i++)
		{
			calculate(i,total);
		}
	}
}

int main()
{	
	scanf("%d", &n);
	scanf("%d", &result);

	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);

	for(int i=0; i<n; i++)
		calculate(i,0);

	printf("%d", answer);
}
