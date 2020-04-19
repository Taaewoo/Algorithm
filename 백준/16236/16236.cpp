#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

#define FOR(x,n,m)  for(int x=n;x<(m);x++)

typedef struct P{
    int x,y,d;
    P(int X, int Y, int D) : x(X), y(Y), d(D) {}
};

int n;
int arr[20][20];
int sx,sy,ss=2,sh=0;
bool visit[20][20];
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int ans = 0;

void cal(vector<pair<int,int>> fish, int dd){
    sort(fish.begin(),fish.end());
    arr[sx][sy] = 0;
    sx = fish[0].first;
    sy = fish[0].second;
    arr[sx][sy] = 0;
    sh++;
    if(sh == ss){
        sh=0;
        ss++;
    }
    ans += dd;
}

bool bfs(){
    int dd = -1;
    memset(visit, false, sizeof(visit));
    queue<P> q;
    q.push(P(sx,sy,0));
    visit[sx][sy] = true;
    vector<pair<int,int>> fish;
    
    while(!q.empty()){
        P cur = q.front(); q.pop();
        
        if(cur.d > dd && dd != -1) break;
        
        if(cur.d == dd && arr[cur.x][cur.y]!=0 && arr[cur.x][cur.y]!=ss) fish.push_back(make_pair(cur.x,cur.y));
        
        FOR(i,0,4){
            int nx = cur.x+dir[i][0], ny = cur.y+dir[i][1];
            if(nx<0||nx>=n||ny<0||ny>=n) continue;
            if(visit[nx][ny]) continue;
            if(arr[nx][ny]>ss) continue;
            
            if(arr[nx][ny]<ss && arr[nx][ny]!=0 && dd==-1) dd = cur.d+1;
            
            visit[nx][ny] = true;
            q.push(P(nx,ny,cur.d+1));
        }
    }
    
    if(dd!=-1){
        cal(fish,dd);
        return true;
    }
    else return false;
}

int main() {
    cin >> n;
    
    FOR(i,0,n){
        FOR(j,0,n){
            cin >> arr[i][j];
            if(arr[i][j]==9){
                sx = i;
                sy = j;
            }
        }
    }
    
    while(1)
        if(!bfs()) break;
    
    cout << ans;
    
    return 0;
}
