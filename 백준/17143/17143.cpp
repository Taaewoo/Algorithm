#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

#define FOR(x,n,m)  for(int x=n;x<(m);x++)

typedef struct S{
    int x,y,s,d,z;
    S(){z=0;}
};

int r,c,m;
S arr[101][101];
int dir[5][2] = {{},{-1,0},{1,0},{0,1},{0,-1}};
int ans = 0;

void move_sh(){
    S temp_arr[101][101];
    
    FOR(i,1,r+1){
        FOR(j,1,c+1){
            if(arr[i][j].z == 0) continue;
            
            S cur = arr[i][j];
            
            FOR(k,0,cur.s){
                if(cur.d==1 && cur.x==1) cur.d=2;
                else if(cur.d==2 && cur.x==r) cur.d=1;
                else if(cur.d==3 && cur.y==c) cur.d=4;
                else if(cur.d==4 && cur.y==1) cur.d=3;
                
                cur.x += dir[cur.d][0];
                cur.y += dir[cur.d][1];
            }
            
            if(temp_arr[cur.x][cur.y].z<cur.z) temp_arr[cur.x][cur.y] = cur;
        }
    }
    memmove(arr,temp_arr,sizeof(arr));
}

void catch_sh(int cur){
    FOR(i,1,r+1){
        if(arr[i][cur].z == 0) continue;
        
        ans += arr[i][cur].z;
        arr[i][cur].z = 0;
        break;
    }
}

int main() {
    cin >> r >> c >> m;
    
    FOR(i,0,m){
        int x,y,s,d,z;
        cin >> x >> y >> s >> d >> z;
        arr[x][y].x = x;
        arr[x][y].y = y;
        arr[x][y].d = d;
        arr[x][y].z = z;
        
        if(d == 1 || d == 2) arr[x][y].s = s%((r-1)*2);
        else arr[x][y].s = s%((c-1)*2);
    }
    
    
    FOR(i,1,c+1){
        catch_sh(i);
        move_sh();
    }
    
    cout << ans;
    
    return 0;
}
