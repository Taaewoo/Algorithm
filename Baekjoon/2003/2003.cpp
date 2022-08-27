#include <iostream>
#include <queue>
using namespace std;

#define FOR(x,n,m)  for(int x=n;x<(m);x++)

int n,m;
int arr[10000];

int main() {
    cin >> n >> m;
    
    FOR(i,0,n) cin >> arr[i];
    
    int s=0, e=0, sum=0, ans=0;
    while(1){
        if(sum >= m) sum -= arr[s++];
        else if(e == n) break;
        else sum += arr[e++];
        
        if(sum == m) ans++;
    }
    cout << ans;
    
    return 0;
}
