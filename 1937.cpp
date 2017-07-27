#include <iostream>
#include <string.h>
using namespace std;

int n, ans=0;
int arr[501][501];
int cache[501][501];
int dir[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };


int dp(int x,int y){ // x,y 에 왔을 때부터 며칠살까
	int& ret = cache[x][y];

	if(ret != -1) return ret;

	int temp=0,max=0;
	for(int i=0; i<4; i++){
		int xx = x+dir[i][0], yy = y+dir[i][1];
		if( xx>=0 && xx<n && yy>=0 && yy<n ){
			if(arr[x][y] < arr[xx][yy]){
				temp = dp(xx, yy);
				if(max < temp) max = temp;
			}
		}
	}

	return ret = max+1;
}

int main(){

	memset(cache,-1,sizeof(cache));

	scanf("%d", &n);

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &arr[i][j]);

	int day;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			day = dp(i,j);
			if(ans < day) ans=day;
		}
	}	

	printf("%d", ans);
}
