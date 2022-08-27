#include <iostream>
using namespace std;

#define FOR(x,n,m)  for(int x=n;x<(m);x++)

int N,S;
int arr[100000];

int main() {
    cin >> N >> S;
    FOR(i,0,N) cin >> arr[i];
    
    int s=0,e=0,sum=0,ans=987654321;
    while(1){
        if(sum >= S){
            ans = min(ans,e-s);
            sum -= arr[s++];
        }
        else if(e == N) break;
        else sum += arr[e++];
    }
    
    cout << (ans==987654321 ? 0 : ans);
}
