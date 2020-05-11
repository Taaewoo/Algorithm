#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

#define FOR(x,n,m)  for(int x=n;x<(m);x++)

typedef struct P{
    int x,y,v;
    P(int X, int Y, int V) : x(X), y(Y), v(V) {}
};

int n,k;
int arr[8][8];
bool visit[8][8];
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int ans = 1;
vector<P> start;

void dfs(int x, int y, int z, int d){
    bool check = false;
    
    FOR(i,0,4){
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
        if(visit[nx][ny]) continue;
        
        if(arr[nx][ny] >= arr[x][y]){
            if(arr[nx][ny] < arr[x][y] + k && z==0){
                int temp = arr[nx][ny];
                arr[nx][ny] = arr[x][y]-1;
                visit[nx][ny] = true;
                dfs(nx,ny,1,d+1);
                visit[nx][ny] = false;
                arr[nx][ny] = temp;
                
                check = true;
            }
        }
        else if(arr[nx][ny] < arr[x][y]){
            visit[nx][ny] = true;
            dfs(nx,ny,z,d+1);
            visit[nx][ny] = false;
            
            check = true;
        }
    }
    
    if(!check){
        ans = max(ans,d);
    }
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case){
        ans = 1;
        start.clear();
        
        cin >> n >> k;
        
        int temp = 0;
        FOR(i,0,n){
            FOR(j,0,n){
                cin >> arr[i][j];
                if(arr[i][j] == temp) start.push_back(P(i,j,arr[i][j]));
                else if(arr[i][j] > temp){
                    start.clear();
                    start.push_back(P(i,j,arr[i][j]));
                    temp = arr[i][j];
                }
            }
        }
        
        FOR(i,0,start.size()){
            visit[start[i].x][start[i].y] = true;
            dfs(start[i].x, start[i].y, 0, 1);
            memset(visit,false,sizeof(visit));
        }
        
        cout << "#" << test_case << " " << ans  << endl;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
