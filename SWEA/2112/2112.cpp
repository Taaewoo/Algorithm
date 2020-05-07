#include <iostream>
#include <string.h>
using namespace std;

#define FOR(x,n,m)  for(int x=n;x<(m);x++)

int d,w,k;
int arr[13][20];
int ans = 987654321;

bool check(){
    FOR(i,0,w){
        bool check = false;
        FOR(j,0,d){
            if(j+k-1 >= d) continue;
            
            bool check2 = true;
            FOR(l,1,k) if(arr[j+l][i] != arr[j][i]) check2 = false;
                
            if(check2){ check = true; break; }
        }
        if(!check) return false;
    }
    return true;
}

void dfs(int x, int n){
    if(check()){
        ans = min(n,ans);
        return;
    }
    
    if(x==d) return;
    if(n>k) return;
    
    int temp[20];
    memmove(temp, arr[x], sizeof(temp));
    
    FOR(i,0,w) arr[x][i] = 0;
    dfs(x+1,n+1);
    memmove(arr[x],temp,sizeof(temp));
    
    FOR(i,0,w) arr[x][i] = 1;
    dfs(x+1,n+1);
    memmove(arr[x],temp,sizeof(temp));
    
    dfs(x+1,n);
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case){
        memset(arr,0,sizeof(arr));
        
        ans = 987654321;
        
        cin >> d >> w >> k;
        
        FOR(i,0,d) FOR(j,0,w) cin >> arr[i][j];
        
        dfs(0,0);
        
        cout << "#" << test_case << " " << ans  << endl;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
