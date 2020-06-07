#include <iostream>
#include <string.h>
#include <algorithm>
#include <map>
using namespace std;

#define FOR(x,n,m)  for(int x=n;x<(m);x++)

int n;
int arr[100001];
bool visit[100001];
int ans;
int s;
bool cycle;
map<int,int> m;

void dfs(int x){
    visit[x] = true;
    m[x]++;
    
    if(m.find(arr[x]) != m.end()){
        s = arr[x];
        if(x != arr[x]) cycle = true;
        return;
    }
    
    if(visit[arr[x]]){
        ans++;
        return;
    }
    
    dfs(arr[x]);
    
    if(!cycle) ans++;
    else
        if(x == s) cycle = false;
    
}

int main() {
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        ans = 0;
        memset(arr,0,sizeof(arr));
        memset(visit,false,sizeof(visit));
        
        cin >> n;
        FOR(i,1,n+1) cin >> arr[i];
        
        // 1 ~ n 시작
        FOR(i,1,n+1){
            // 방문한 노드면 패스
            if(visit[i]) continue;
            
            // 시작점 초기화
            s=-1;
            cycle = false;
            m.clear();
            dfs(i);
        }
    
        cout << ans <<endl;
    }
    return 0;
}
