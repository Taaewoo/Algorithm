#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int n, ans=0;
string fir, sec;
int cache[1001][1001];

int dp(int in1,int in2){
	if(in1 == fir.size() || in2 == sec.size()) return 0;

	int& ret= cache[in1][in2];

	if(ret != -1) return ret;

	if(fir[in1] == sec[in2]) return ret = dp(in1+1,in2+1)+1;
	else return ret = max(dp(in1,in2+1),dp(in1+1,in2));
}

int main(){
	
	memset(cache,-1,sizeof(cache));

	cin>> fir >> sec;

	ans = dp(0,0);

	printf("%d", ans);
}
