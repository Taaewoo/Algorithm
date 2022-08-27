#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

#define FOR(x,n,m)  for(int x=n;x<(m);x++)

typedef struct C{
    int r,c,s;
    C(int R, int C, int S) : r(R), c(C), s(S) {}
};

int n,m,k;
int arr[50][50];
vector<C> com;
vector<int> per;
int ans = 987654321;

void rot(int idx){
    int temp[50][50];
    memmove(temp,arr,sizeof(arr));
    
    C cur = com[per[idx]];
    FOR(i,1,cur.s+1){
        for(int j=cur.c-i; j<cur.c+i; j++) arr[cur.r-i][j+1] = temp[cur.r-i][j];
        for(int j=cur.r-i; j<cur.r+i; j++) arr[j+1][cur.c+i] = temp[j][cur.c+i];
        for(int j=cur.c+i; j>cur.c-i; j--) arr[cur.r+i][j-1] = temp[cur.r+i][j];
        for(int j=cur.r+i; j>cur.r-i; j--) arr[j-1][cur.c-i] = temp[j][cur.c-i];
    }
}

int main() {
    cin >> n >> m >> k;
    
    FOR(i,0,n) FOR(j,0,m) cin >> arr[i][j];
    
    FOR(i,0,k){
        int r,c,s; cin >> r >> c >> s;
        com.push_back(C(r-1,c-1,s));
    }
    
    FOR(i,0,k) per.push_back(i);
    
    int arr_copy[50][50];
    memmove(arr_copy, arr, sizeof(arr));
    
    do{
        FOR(i,0,per.size()) rot(i);
        
        FOR(i,0,n){
            int sum = 0;
            FOR(j,0,m){
                sum += arr[i][j];
            }
            ans = min(ans,sum);
        }
        
        memmove(arr,arr_copy,sizeof(arr));
    }while(next_permutation(per.begin(), per.end()));
    
    cout << ans;
    
    return 0;
}
