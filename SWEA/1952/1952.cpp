#include <iostream>
using namespace std;

#define FOR(x,n,m)  for(int x=n;x<(m);x++)

int c[4], m[12];
int ans;

void dfs(int x, int sum){
    if(x>=12){
        ans = min(ans, sum);
        return;
    }
    
    if(m[x]==0){
        dfs(x+1,sum);
        return;
    }
    
    m[x]*c[0] < c[1] ? dfs(x+1, sum+m[x]*c[0]) : dfs(x+1, sum+c[1]);
    
    dfs(x+3, sum+c[2]);
}

int main() {
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        FOR(i,0,4) cin >> c[i];
        FOR(i,0,12) cin >> m[i];
        
        ans = c[3];
        
        dfs(0,0);
    
        cout << "#" << test_case << " " << ans <<endl;
    }
    return 0;
}
