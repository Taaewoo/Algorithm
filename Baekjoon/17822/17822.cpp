#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

#define FOR(x,n,m)  for(int x=n;x<(m);x++)

typedef struct P{
    int x,y;
    P(int X, int Y) : x(X), y(Y) {}
};

typedef struct C{
    int x,d,k;
    C(int X, int D, int K) : x(X), d(D), k(K) {}
};

int n,m,t;
int arr[50][50];
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
vector<C> c;
int ans = 0;

bool bfs(int x, int y){
    if(arr[x][y]==-1) return false;
    
    bool visit[50][50] = {0,};
    vector<P> del;
    queue<P> q;
    q.push(P(x,y));
    visit[x][y] = true;
    del.push_back(P(x,y));
    while(!q.empty()){
        P cur = q.front(); q.pop();
        
        FOR(i,0,4){
            int nx = cur.x + dir[i][0], ny = cur.y + dir[i][1];
            if(ny==-1) ny = m-1;
            else if(ny==m) ny = 0;
            
            if(nx<0 || nx>=n || visit[nx][ny]) continue;
            if(arr[cur.x][cur.y] != arr[nx][ny]) continue;
            
            visit[nx][ny] = true;
            q.push(P(nx,ny));
            del.push_back(P(nx,ny));
        }
    }
    
    if(del.size() == 1) return false;
    else FOR(i,0,del.size()) arr[del[i].x][del[i].y] = -1;
    
    return true;
}

void rot(int idx, int k){
    int temp_arr[50][50];
    memmove(temp_arr,arr,sizeof(arr));
    FOR(i,0,m){
        if(i-k < 0) arr[idx][i] = temp_arr[idx][m+i-k];
        else arr[idx][i] = temp_arr[idx][i-k];
    }
}

void com(int idx){
    FOR(i,0,n){
        if((i+1)%c[idx].x != 0) continue;
        
        rot(i,c[idx].k);
    }
    
    bool check = false;
    FOR(j,0,n){
        FOR(k,0,m){
            if(bfs(j,k)) check = true;
        }
    }
    
    float sum = 0;
    float avg;
    if(!check){
        int cnt = 0;
        FOR(j,0,n){
            FOR(k,0,m){
                if(arr[j][k]==-1) continue;
                
                sum+=arr[j][k];
                cnt++;
            }
        }
        avg = sum/cnt;
        
        FOR(j,0,n){
            FOR(k,0,m){
                if(arr[j][k]==-1) continue;
                
                if(arr[j][k]>avg) arr[j][k]--;
                else if(arr[j][k]<avg) arr[j][k]++;
            }
        }
    }
}

int main() {
    cin >> n >> m >> t;
    
    FOR(i,0,n) FOR(j,0,m) cin >> arr[i][j];
    
    FOR(i,0,t){
        int x,d,k; cin >> x >> d >> k;
        if(d==1){
            d = 0;
            k = m - k;
        }
        c.push_back(C(x,d,k));
    }
    
    FOR(i,0,c.size()) com(i);
    
    FOR(i,0,n) FOR(j,0,m) if(arr[i][j]!=-1) ans+=arr[i][j];
    
    cout << ans;
    return 0;
}
