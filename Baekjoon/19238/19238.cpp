#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;

#define FOR(x,n,m) for(int x=n; x<(m); x++)

struct P{
    int sx,sy,ex,ey,n,s=1;
    
    P(int SX, int SY, int EX, int EY, int N) :
        sx(SX), sy(SY), ex(EX), ey(EY), n(N) {}
    
    bool operator <(const P& pp)const{
        if(sx > pp.sx) return false;
        else if(sx == pp.sx){
            if(sy > pp.sy) return false;
            else return true;
        }
        else return true;
    }
};

struct T{
    int x,y,d,f;
    T(int X, int Y, int D, int F) : x(X), y(Y), d(D), f(F) {}
};

int n,m,k;
int arr[20][20];
vector<P> p;
int tx,ty;
bool visit[20][20];
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

bool bfs2(int sx, int sy, int ex, int ey){
    bool visit[20][20];
    memset(visit, 0, sizeof(visit));
    
    queue<T> q;
    q.push(T(sx,sy,0,k));
    visit[sx][sy] = true;
    while(!q.empty()){
        T cur = q.front(); q.pop();
        
        if(cur.x == ex && cur.y == ey){
            k += cur.d;
            return true;
        }
        
        if(cur.f == 0) continue;
        
        FOR(i,0,4){
            int nx = cur.x+dir[i][0], ny = cur.y+dir[i][1];
            
            if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
            if(visit[nx][ny]) continue;
            if(arr[nx][ny] == 1) continue;
            
            visit[nx][ny] = true;
            q.push(T(nx,ny,cur.d+1,cur.f-1));
        }
    }
    
    return false;
}

bool bfs(){
    memset(visit,0,sizeof(visit));
    
    queue<T> q;
    q.push(T(tx,ty,0,k));
    visit[tx][ty] = true;
    
    int check = -1;
    vector<P> people;
    while(!q.empty()){
        T cur = q.front(); q.pop();
        
        if(check!=-1 && cur.d > check) break;
        
        FOR(i,0,p.size()){
            if(p[i].s == 0) continue;
            if(cur.x == p[i].sx && cur.y == p[i].sy){
                people.push_back(p[i]);
                check = cur.d;
            }
        }
        
        if(cur.f == 0) continue;
        
        FOR(i,0,4){
            int nx = cur.x+dir[i][0], ny = cur.y+dir[i][1];
            
            if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
            if(visit[nx][ny]) continue;
            if(arr[nx][ny] == 1) continue;
            
            visit[nx][ny] = true;
            q.push(T(nx,ny,cur.d+1,cur.f-1));
        }
    }
    
    if(people.size()==0){
        k = -1;
        return false;
    }
    
    sort(people.begin(),people.end());
    
    k -= check;
    
    bool check2 = false;
    FOR(i,0,people.size()){
        if(bfs2(people[i].sx, people[i].sy, people[i].ex, people[i].ey)){
            tx = people[i].ex;
            ty = people[i].ey;
            
            p[people[i].n].s = 0;
            check2 = true;
            break;
        };
    }
    if(!check2){
        k = -1;
        return false;
    }
    
    return true;
}

int main()
{
    cin >> n >> m >> k;
    
    FOR(i,0,n) FOR(j,0,n) cin >> arr[i][j];
    
    cin >> tx >> ty;
    
    tx--; ty--;
    
    FOR(i,0,m){
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        p.push_back(P(sx-1,sy-1,ex-1,ey-1,i));
    }
    
    while(1){
        bool check = false;
        FOR(i,0,p.size()){
            if(p[i].s == 0) continue;
            check = true;
        }
        if(!check) break;
        
        if(!bfs()) break;
        
        
    }
    
    cout << k;
    
    return 0;
}
