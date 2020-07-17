#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

#define FOR(x,n,m) for(int x=n; x<(m); x++)

typedef struct F
{
    int n,d,s=1;
};

typedef struct S
{
    int x,y,d;
};

F f[4][4];
S sh;
vector<pair<int,pair<int,int>>> seq;
int dir[9][2] = { {}, {-1,0}, {-1,-1}, {0,-1},
                  {1,-1}, {1,0}, {1,1},
                  {0,1}, {-1,1} };
int ans = 0;

bool range(int x, int y){
    if(x<0 || x>=4 || y<0 || y>=4) return false;
    else return true;
}

void move(){
    FOR(i,0,seq.size()){
        int x = seq[i].second.first, y = seq[i].second.second;
        int d = f[x][y].d, n = f[x][y].n;
        if(f[x][y].s == 0) continue;
        
        bool check = true;
        int nx = x + dir[d][0], ny = y + dir[d][1];
        while((nx == sh.x && ny == sh.y) || !range(nx,ny) ){
            if(++d==9) d = 1;
            if(d == f[x][y].d){
                check = false;
                break;
            }

            nx = x + dir[d][0];
            ny = y + dir[d][1];
        }
        if(!check) continue;

        f[x][y].d = d;

        seq[i].second.first = nx;
        seq[i].second.second = ny;

        // 순서 vector 위치 바꾸기
        int tempN = f[nx][ny].n;
        seq[f[nx][ny].n-1].second.first = x;
        seq[f[nx][ny].n-1].second.second = y;

        //위치 바꾸기
        F temp = f[nx][ny];
        f[nx][ny] = f[x][y];
        f[x][y] = temp;
    }
}

void dfs(int x, int y, int sum, int dep){
    ans = max(ans,sum);

    F temp_f[4][4];
    memmove(temp_f,f,sizeof(f));
    vector<pair<int,pair<int,int>>> temp_seq = seq;

    move();

    int nx = x, ny = y;
    while(1){
        nx += dir[sh.d][0];
        ny += dir[sh.d][1];

        if(!range(nx,ny)) break;

        if(f[nx][ny].s == 0) continue;

        int tempD = sh.d;

        f[nx][ny].s = 0;
        sh.x = nx;
        sh.y = ny;
        sh.d = f[nx][ny].d;

        dfs(nx,ny,sum+f[nx][ny].n,dep+1);
        f[nx][ny].s = 1;
        sh.x = x;
        sh.y = y;
        sh.d = tempD;
    }

    memmove(f,temp_f,sizeof(f));
    seq = temp_seq;
}

int main()
{
    FOR(i,0,4){
        FOR(j,0,4){
            int num,dir; cin >> num >> dir;
            f[i][j].n = num;
            f[i][j].d = dir;
            pair<int,pair<int,int>> p;
            p.first = num;
            p.second = make_pair(i,j);
            seq.push_back(p);
        }
    }

    sh.x = 0;
    sh.y = 0;
    sh.d = f[0][0].d;
    f[0][0].s = 0;

    sort(seq.begin(), seq.end());
    
    dfs(sh.x, sh.y, f[0][0].n, 0);

    cout << ans;

    return 0;
}
