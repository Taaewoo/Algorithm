#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(x,n,m)  for(int x=n;x<(m);x++)

int n;
int arr[20][20];
int z[20][20];
int ans = 987654321;

void split(int x, int y, int d1, int d2){
    if(y-d1<0 || y+d2>=n || x+d1+d2>=n) return;
    
    FOR(i,0,20) FOR(j,0,20) z[i][j] = 5;
    
    //1
    int lx = x, ly = y;
    FOR(i,0,x+d1){
        FOR(j,0,n){
            if(i==lx && j==ly){
                lx++;
                ly--;
                break;
            }
            else if(j>y) break;
            z[i][j] = 1;
        }
    }
    //3
    lx = x+d1;
    ly = y-d1;
    FOR(i,x+d1,n){
        FOR(j,0,n){
            if(i==lx && j==ly){
                lx++;
                ly++;
                break;
            }
            else if(j>=y-d1+d2) break;
            z[i][j] = 3;
        }
    }
    //2
    lx = x;
    ly = y;
    FOR(i,0,x+d2+1){
        for(int j=n-1; j>=0; j--){
            if(i==lx && j==ly){
                lx++;
                ly++;
                break;
            }
            else if(j<=y) break;
            z[i][j] = 2;
        }
    }
    //4
    lx = x+d2+1;
    ly = y+d2-1;
    FOR(i,x+d2+1,n){
        for(int j=n-1; j>=0; j--){
            if(i==lx && j==ly){
                lx++;
                ly--;
                break;
            }
            else if(j<y-d1+d2) break;
            z[i][j] = 4;
        }
    }

    int zSum[5]={0,};
    FOR(i,0,n) FOR(j,0,n) zSum[z[i][j]-1] += arr[i][j];
    
    int d = *max_element(zSum, zSum+5) - *min_element(zSum, zSum+5);
    ans = min(ans,d);
}

int main() {
    cin >> n;
    
    FOR(i,0,n) FOR(j,0,n) cin >> arr[i][j];
    
    FOR(i,0,n) FOR(j,0,n) FOR(d1,1,n) FOR(d2,1,n) split(i,j,d1,d2);
    
    cout << ans;
    
    return 0;
}
