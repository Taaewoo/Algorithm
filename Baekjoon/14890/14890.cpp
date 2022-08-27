#include <iostream>
#include <string.h>
using namespace std;

#define FOR(x,n,m)  for(int x=n;x<(m);x++)

int n,l;
int arr[101][101];
int ans = 0;

bool hor(int r){
    bool check[101] = {false,};
    FOR(i,0,n-1){
        if(arr[r][i] == arr[r][i+1]) continue;
        if(abs(arr[r][i] - arr[r][i+1]) > 1) return false;
        else if(arr[r][i] - arr[r][i+1] == 1){
            if(i+l >= n) return false;
            check[i+1]=true;
            FOR(j,1,l){
                if(arr[r][i+j] != arr[r][i+j+1]) return false;
                check[i+j+1] = true;
            }
            i+=(l-1);
        }
        else if(arr[r][i] - arr[r][i+1] == -1){
            if(check[i]) return false;
            if(i-l+1 < 0) return false;
            FOR(j,0,l-1)
                if(arr[r][i-j] != arr[r][i-j-1] || check[i-j] || check[i-j-1])
                    return false;
        }
    }
    return true;
}

void rot(){
    int temp[101][101];
    FOR(i,0,n) FOR(j,0,n) temp[i][j] = arr[n-j-1][i];
    memmove(arr,temp,sizeof(temp));
}

int main() {
    
    cin >> n >> l;
    
    FOR(i,0,n) FOR(j,0,n) cin >> arr[i][j];
    
    FOR(i,0,n)
        if(hor(i)) ans++;
        
    rot();
    
    FOR(i,0,n) if(hor(i)) ans++;
    
    cout << ans;
    
    return 0;
}
