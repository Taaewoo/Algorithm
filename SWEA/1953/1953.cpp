#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

#define FOR(x,n,m)  for(int x=n;x<(m);x++)

typedef struct P{
    int x,y,d;
    P(int X, int Y, int D) : x(X), y(Y), d(D) {}
};

int n,m,r,c,l;
int arr[50][50];
bool visit[50][50];
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
vector<int> tn[8] = { {}, {0,1,2,3}, {0,2}, {1,3}, {0,1}, {1,2}, {2,3}, {3,0} };

int bfs(){
    int ans = 1;
    queue<P> q;
    q.push(P(r,c,1));
    visit[r][c] = true;
    while(!q.empty()){
        P cur = q.front(); q.pop();
        
        if(cur.d >= l) break;
        
        FOR(i,0,tn[arr[cur.x][cur.y]].size()){
            int d = tn[arr[cur.x][cur.y]][i];
            int nx = cur.x+dir[d][0], ny = cur.y+dir[d][1];
            
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(visit[nx][ny] || arr[nx][ny]==0) continue;
            
            bool check = false;
            FOR(j,0,tn[arr[nx][ny]].size()) if((tn[arr[nx][ny]][j]+2)%4 == d) check = true;
            if(!check) continue;
            
            visit[nx][ny] = true;
            q.push(P(nx,ny,cur.d+1));
            ans++;
        }
    }
    
    return ans;
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        memset(visit,false,sizeof(visit));
        
        cin >> n >> m >> r >> c >> l;
        
        FOR(i,0,n) FOR(j,0,m) cin >> arr[i][j];
        
        cout << "#" << test_case << " " << bfs() << endl;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
