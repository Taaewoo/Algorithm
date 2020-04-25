#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FOR(x,n,m)  for(int x=n;x<(m);x++)

typedef struct H{
    int x,y,d,i;
    H(int X, int Y, int D, int I) : x(X), y(Y), d(D), i(I) {}
};

int n,k;
int arr[12][12];
int dir[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
vector<H> h;
vector<int> v[12][12];
int ans = -1;

bool move(){
    FOR(i,0,h.size()){
        int x = h[i].x, y = h[i].y;
        int d = h[i].d;
        int nx = x + dir[d][0], ny = y + dir[d][1];
        
        vector<int> temp;
        vector<int>::iterator it = find(v[x][y].begin(), v[x][y].end(), i);
        for(auto j=it; j!=v[x][y].end(); j++) temp.push_back(*j);
        
        if(arr[nx][ny]==2 || nx<0 || nx>=n || ny<0 || ny>=n){
            if(h[i].d==0) h[i].d=1;
            else if(h[i].d==1) h[i].d=0;
            else if(h[i].d==2) h[i].d=3;
            else if(h[i].d==3) h[i].d=2;
            
            d = h[i].d;
            nx = x + dir[d][0];
            ny = y + dir[d][1];
            
            if(arr[nx][ny]==2 || nx<0 || nx>=n || ny<0 || ny>=n) continue;
        }
        
        if(arr[nx][ny]==1){
            reverse(temp.begin(),temp.end());
        }
        
        FOR(j,0,temp.size()){
            v[nx][ny].push_back(temp[j]);
            v[x][y].pop_back();
            h[temp[j]].x = nx;
            h[temp[j]].y = ny;
        }
        
        if(v[nx][ny].size()>=4) return true;
    }
    
    return false;
}

int main() {
    cin >> n >> k;
    
    FOR(i,0,n) FOR(j,0,n) cin >> arr[i][j];
    
    FOR(j,0,k){
        int x,y,d; cin >> x >> y >> d;
        h.push_back(H(x-1,y-1,d-1,j));
        v[x-1][y-1].push_back(j);
    }
    
    FOR(i,0,1000){
        if(move()){
            ans = i+1;
            break;
        }
    }
    
    cout << ans;
    return 0;
}
