#include <iostream>
using namespace std;

#define FOR(x,n,m)  for(int x=n;x<(m);x++)

int n,m,h;
int arr[31][11];
int ans = 987654321;

bool check(){
    FOR(i,0,n){
        int s = i;
        bool visit[31][11] = {false,};
        FOR(j,0,h){
            if(s>0 && s<n-1){
                if(arr[j][s-1]==1 && !visit[j][s-1]){
                    visit[j][s-1] = true;
                    s--;
                }
                else if(arr[j][s]==1 && !visit[j][s]){
                    visit[j][s] = true;
                    s++;
                }
            }
            else if(s==0){
                if(arr[j][s]==1 && !visit[j][s]){
                    visit[j][s] = true;
                    s++;
                }
            }
            else if(s==n-1){
                if(arr[j][s-1]==1 && !visit[j][s-1]){
                    visit[j][s-1] = true;
                    s--;
                }
            }
        }
        
        if(s!=i) return false;
    }
    return true;
}

void dfs(int x, int y, int d){
    if(d>=3) return;
    if(y>=n-1){x++; y=0;}
    if(x==h) return;
    
    if(arr[x][y]==1){
        dfs(x,y+1,d);
        return;
    }
    else if(y!=0 && y!=n-2){
        if(arr[x][y-1] == 1 || arr[x][y+1] == 1){
            dfs(x,y+1,d);
            return;
        }
    }
    else if(y<n-2){
        if(arr[x][y+1] == 1){
            dfs(x,y+2,d);
            return;
        }
    }
    else if(y>0){
        if(arr[x][y-1] == 1){
            dfs(x,y+1,d);
            return;
        }
    }
    
    arr[x][y] = 1;
    if(check()){
        ans = min(ans,d+1);
    }
    dfs(x,y+1,d+1);
    arr[x][y] = 0;
    
    dfs(x,y+1,d);
}

int main() {
    
    cin >> n >> m >> h;
    
    FOR(i,0,m){
        int x,y;
        cin >> x >> y;
        arr[x-1][y-1] = 1;
    }
    if(check()){ cout << "0"; return 0;}
    
    dfs(0,0,0);
    
    if(ans == 987654321) cout << "-1";
    else cout << ans;

    return 0;
}
