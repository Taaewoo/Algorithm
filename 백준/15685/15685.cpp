#include <iostream>
#include <vector>
using namespace std;

#define FOR(x,n,m)  for(int x=n;x<(m);x++)

typedef struct DC{
    int x, y, d, g;
    DC(int X, int Y, int D, int G) : x(X), y(Y), d(D), g(G) {}
};

int n;
vector<DC> v;
int arr[101][101];
int dir[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};

void make_DC(DC dc){
    vector<int> dv;
    arr[dc.y][dc.x] = 1;
    arr[dc.y+dir[dc.d][0]][dc.x+dir[dc.d][1]] = 1;
    dv.push_back(dc.d);
    int ey=dc.y+dir[dc.d][0], ex=dc.x+dir[dc.d][1];
    
    FOR(i,1,dc.g+1){
        vector<int> tempV;
        for(int j=int(dv.size())-1; j>=0; j--){
            int tempD = (dv[j]+1)%4;
            ey+=dir[tempD][0];
            ex+=dir[tempD][1];
            arr[ey][ex] = 1;
            tempV.push_back(tempD);
        }
        for(int e : tempV)
            dv.push_back(e);
    }
}

int main() {
    cin >> n;
    
    FOR(i,0,n){
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        v.push_back(DC(x,y,d,g));
    }
    
    FOR(i,0,v.size()) make_DC(v[i]);
        
    int ans = 0;
    FOR(i,0,100)
        FOR(j,0,100)
            if(arr[i][j]==1 && arr[i+1][j]==1 && arr[i][j+1]==1 && arr[i+1][j+1]==1)
                ans++;
    
    cout << ans;
    return 0;
}
