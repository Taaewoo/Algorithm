#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

#define FOR(x,n,m)  for(int x=n;x<(m);x++)

typedef struct MI{
    int x,y,g,d,s=1;
    MI(int X, int Y, int G, int D) : x(X), y(Y), g(G), d(D) {}
};

int n,m,k;
vector<MI> v;
int arr[100][100];
int sum[100][100];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int turn[4] = {1,0,3,2};

void move(){
    int temp_arr[100][100];
    memset(temp_arr,-1,sizeof(temp_arr));
    memset(sum,0,sizeof(sum));
    
    FOR(i,0,v.size()){
        if(v[i].s == 0) continue;
        
        int x = v[i].x, y = v[i].y;
        int nx = x + dir[v[i].d][0], ny = y + dir[v[i].d][1];
        
        if(nx==0 || nx==n-1 || ny==0 || ny==n-1){
            v[i].d = turn[v[i].d];
            v[i].g/=2;
            if(v[i].g == 0) v[i].s = 0;
        }
        
        if(temp_arr[nx][ny]!=-1){
            if(v[i].g > v[temp_arr[nx][ny]].g){
                sum[nx][ny] += v[temp_arr[nx][ny]].g;
                v[temp_arr[nx][ny]].s = 0;
            }
            else if(v[i].g < v[temp_arr[nx][ny]].g){
                sum[nx][ny] += v[i].g;
                v[i].s = 0;
            }
        }
        
        v[i].x = nx;
        v[i].y = ny;
        
        if(v[i].s == 1) temp_arr[nx][ny] = i;
    }
    
    FOR(i,0,n){
        FOR(j,0,n){
            if(temp_arr[i][j]==-1) continue;
            
            v[temp_arr[i][j]].g += sum[i][j];
        }
    }
    
    memmove(arr,temp_arr,sizeof(temp_arr));
}

int main() {
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        v.clear();
        memset(arr,-1,sizeof(arr));
        
        cin >> n >> m >> k;
        
        FOR(i,0,k){
            int x,y,g,d;
            cin >> x >> y >> g >> d;
            v.push_back(MI(x,y,g,d-1));
            arr[x][y] = i;
        }
        
        FOR(i,0,m) move();
        
        int ans = 0;
        FOR(i,0,n)
            FOR(j,0,n)
                if(arr[i][j]!=-1) ans += v[arr[i][j]].g;
        
        cout << "#" << test_case << " " << ans << endl;
    }
    return 0;
}
