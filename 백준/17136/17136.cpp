#include <iostream>
#include <string.h>
using namespace std;

#define FOR(x,n,m)  for(int x=n;x<(m);x++)

int arr[10][10];
bool visit[10][10];
int type_n[5]={5,5,5,5,5};
int ans = 987654321;
int cnt = 0;

void place(int x, int y, int n){
    if(y>=10){ x++; y=0; }
    if(x==10 || cnt==0){
        ans = min(n,ans);
        return;
    }
    
    if(visit[x][y] || arr[x][y]==0){
        place(x,y+1,n);
        return;
    }
    
    for(int i=4; i>=0; i--){
        if(x+i>=10 || y+i>=10 || type_n[i] == 0) continue;
        
        bool check = true;
        FOR(j,0,i+1)
            FOR(k,0,i+1)
                if(arr[x+j][y+k] == 0 || visit[x+j][y+k]) check = false;
        
        if(!check) continue;
        
        FOR(j,0,i+1)
            FOR(k,0,i+1)
                visit[x+j][y+k] = true;
        type_n[i]--;
        cnt -= (i+1)*(i+1);
        
        place(x,y+i+1,n+1);
        
        FOR(j,0,i+1)
            FOR(k,0,i+1)
                visit[x+j][y+k] = false;
        type_n[i]++;
        cnt += (i+1)*(i+1);
    }
    
    return;
}

int main() {
    FOR(i,0,10) FOR(j,0,10){
        cin >> arr[i][j];
        if(arr[i][j] == 1) cnt++;
    }
        
    place(0,0,0);
    
    cout << (ans==987654321 ? -1 : ans);
    return 0;
}
