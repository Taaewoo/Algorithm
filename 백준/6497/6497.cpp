#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define FOR(x,n,m)  for(int x=n;x<(m);x++)

typedef struct P{
    int x,y;
    P(int X, int Y) : x(X), y(Y) {}
};

typedef struct B{
    int s,e,l;
    B(int S, int E, int L) : s(S), e(E), l(L) {}
};

int n,m;
int arr[100][100];
bool visit[100][100];
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
vector<P> z[7];
vector<B> b;
int ans = 987654321;

bool range(int x, int y){
    if(x<0 || x>=n || y<0 || y>=m) return false;
    return true;
}

bool bfs(int x, int y, int num){
    if(visit[x][y] || arr[x][y]==0) return false;
    
    queue<P> q;
    q.push(P(x,y));
    visit[x][y] = true;
    arr[x][y] = num;
    z[num].push_back(P(x,y));
    while(!q.empty()){
        P cur = q.front(); q.pop();
        
        FOR(i,0,4){
            int nx = cur.x + dir[i][0], ny = cur.y + dir[i][1];
            if(!range(nx,ny)) continue;
            if(visit[nx][ny]) continue;
            if(arr[nx][ny] == 0) continue;
            
            visit[nx][ny] = true;
            arr[nx][ny] = num;
            z[num].push_back(P(nx,ny));
            q.push(P(nx,ny));
        }
    }
    
    return true;
}

void build(P p,int num){
    int nx = p.x, ny =p.y;
    int length = 0;
    do{
        ny++;
        if(arr[nx][ny]!=0 && arr[nx][ny]!=num && length>=2)
            b.push_back(B(num,arr[nx][ny],length));
        
        if(arr[nx][ny] != 0) break;
        length++;
    }while(arr[nx][ny]==0 && range(nx,ny));
    
    nx = p.x;
    ny = p.y;
    length = 0;
    do{
        nx++;
        if(arr[nx][ny]!=0 && arr[nx][ny]!=num && length>=2)
            b.push_back(B(num,arr[nx][ny],length));
        
        if(arr[nx][ny] != 0) break;
        length++;
    }while(arr[nx][ny]==0 && range(nx,ny));
}

int main() {
    cin >> n >> m;
    
    FOR(i,0,n) FOR(j,0,m) cin >> arr[i][j];
    
    int num = 1;
    FOR(i,0,n){
        FOR(j,0,m){
            if(bfs(i,j,num)) num++;
        }
    }
    
    FOR(i,1,num) FOR(j,0,z[i].size()) build(z[i][j],i);
    
    vector<int> per;
    FOR(i,0,b.size()) i>=(b.size() - (num-2)) ? per.push_back(1) : per.push_back(0);
    
    do{
        int dis = 0;
        vector<int> idx;
        FOR(i,0,per.size()){
            if(per[i] == 0) continue;
            
            idx.push_back(i);
            dis += b[i].l;
        }
        
        bool visit_z[7];
        FOR(i,0,7) visit_z[i] = false;
        queue<int> q;
        q.push(1);
        visit_z[1] = true;
        while(!q.empty()){
            int cur = q.front(); q.pop();
            
            FOR(i,0,idx.size()){
                int ne;
                
                if(b[idx[i]].s == cur) ne = b[idx[i]].e;
                else if(b[idx[i]].e == cur) ne = b[idx[i]].s;
                else continue;
                
                if(visit_z[ne]) continue;
                
                visit_z[ne] = true;
                q.push(ne);
            }
        }
        
        bool all_pass = true;
        FOR(i,1,num){
            if(visit_z[i]) continue;
            all_pass = false;
            break;
        }
        if(all_pass){
            ans = min(ans,dis);
        }
        
    }while(next_permutation(per.begin(), per.end()));
    
    cout << (ans==98765431 ? -1 : ans);
}
