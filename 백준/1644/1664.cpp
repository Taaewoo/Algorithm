#include <iostream>
#include <queue>
using namespace std;

#define FOR(x,n,m)  for(int x=n;x<(m);x++)

int n;
int check[4000001];

int next(int x){
    FOR(i,x,n+1){
        if(check[i]==1) return i;
        else if(check[i]==-1) continue;
        
        bool temp = true;
        for(int j=2; j*j<=i; j++){
            if(i%j == 0){
                temp = false;
                break;
            }
        }
        if(temp){
            check[i] = 1;
            return i;
        }
        else{
            check[i] = -1;
        }
    }
    
    return -1;
}

int main() {
    cin >> n;
    
    int s=2, e=2, sum=0, ans=0;
    while(1){
        if(sum >= n){
            sum -= s;
            s = next(s+1);
        }
        else if(e==-1) break;
        else if(sum < n){
            sum += e;
            e = next(e+1);
        }
        
        if(sum == n) ans++;
    }
    
    cout << ans;
    return 0;
}
