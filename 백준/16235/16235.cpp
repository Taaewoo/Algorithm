#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FOR(x,n,m)  for(int x=n;x<(m);x++)

int n,m,k;
int A[11][11];
int arr[11][11];
vector<int> v[11][11];
int dir[8][2] = {{-1,-1}, {-1,0}, {-1,1},
                {0,-1}, {0,1},
                {1,-1}, {1,0}, {1,1} };
                

void year(int y){
    vector<int> death[11][11];
    
    //Spring
    FOR(i,0,n){
        FOR(j,0,n){
            int temp = 0;
            sort(v[i][j].begin(), v[i][j].end());
            FOR(k,0,v[i][j].size()){
                
                if(arr[i][j] >= v[i][j][k]){
                    arr[i][j] -= v[i][j][k];
                    v[i][j][k]++;
                }
                else{
                    temp+=v[i][j][k]/2;
                    //death[i][j].push_back(v[i][j][k].first);
                    v[i][j].erase(v[i][j].begin()+k);
                    k--;
                }
            }
            arr[i][j] += temp;
        }
    }
//
//    //Summer
//    FOR(i,0,n)
//        FOR(j,0,n)
//            FOR(k,0,death[i][j].size())
//                arr[i][j] += death[i][j][k]/2;
//
    
    //Fall
    FOR(i,0,n){
        FOR(j,0,n){
            FOR(k,0,v[i][j].size()){
                if(v[i][j][k]%5 == 0){
                    FOR(l,0,8){
                        int nx = i+dir[l][0], ny = j+dir[l][1];
                        if(nx<0||nx>=n||ny<0||ny>=n) continue;
                        v[nx][ny].push_back(1);
                    }
                }
            }
        }
    }
    
    //Winter
    FOR(i,0,n){
        FOR(j,0,n){
            arr[i][j] += A[i][j];
        }
    }
}

int main() {
    cin >> n >> m >> k;
    FOR(i,0,n) FOR(j,0,n) cin >> A[i][j];
    
    FOR(i,0,m){
        int x,y,z; cin >> x >> y >> z;
        v[x-1][y-1].push_back(z);
    }
    
    FOR(i,0,n) FOR(j,0,n) arr[i][j]=5;
    
    FOR(i,0,k) year(i);
    
    int ans = 0;
    FOR(i,0,n) FOR(j,0,n) FOR(k,0,v[i][j].size()) ans++;
    
    cout << ans;
    return 0;
}
