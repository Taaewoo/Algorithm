#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

#define FOR(x,n,m)  for(int x=n;x<(m);x++)

typedef struct V{
    int x,y,d;
    V(int X, int Y, int D) : x(X), y(Y), d(D) {}
};

int n,m;
int arr[50][50];
bool visit[50][50];
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
vector<V> virus;
vector<V> active;
int fAns = 987654321;

bool bfs(){
    memset(visit,false,sizeof(visit));
    int temp_arr[50][50];
    memmove(temp_arr,arr,sizeof(arr));
    
    queue<V> q;
    FOR(i,0,active.size()){
        q.push(V(active[i].x,active[i].y,0));
        visit[active[i].x][active[i].y] = true;
    }
    int ans = 0;
    
    int blank = 0;
    FOR(i,0,n)
        FOR(j,0,n)
            if(temp_arr[i][j]==0) blank++;
    
    if(blank==0){
        fAns = 0;
        return true;
    }
    
    while(!q.empty()){
        V cur = q.front(); q.pop();
        
        bool check = false;
        FOR(i,0,4){
            int nx = cur.x + dir[i][0], ny = cur.y + dir[i][1];
            if(nx<0||nx>=n||ny<0||ny>=n) continue;
            if(visit[nx][ny] || temp_arr[nx][ny]==1) continue;
            
            visit[nx][ny] = true;
            if(temp_arr[nx][ny]==0) blank--;
            temp_arr[nx][ny] = 2;
            q.push(V(nx,ny,cur.d+1));
            ans = cur.d+1;
            if(blank==0) check = true;
        }
        if(check) break;
    }
    
    if(blank==0) fAns = min(fAns,ans);
    
    return true;
}

void dfs(int idx, int vN){
    if(vN>=m){
        bfs();
        return;
    }
    
    if(idx>=virus.size()) return;
    
    arr[virus[idx].x][virus[idx].y] = 2;
    active.push_back(virus[idx]);
    dfs(idx+1,vN+1);
    arr[virus[idx].x][virus[idx].y] = -1;
    active.pop_back();
    
    dfs(idx+1,vN);
}

int main() {
    cin >> n >> m;
    
    FOR(i,0,n){
        FOR(j,0,n){
            cin >> arr[i][j];
            if(arr[i][j]==2){
                virus.push_back(V(i,j,0));
                arr[i][j]=-1;
            }
        }
    }
    
    dfs(0,0);
    
    cout << (fAns==987654321 ? -1:fAns);
    
    return 0;
}
