#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

#define FOR(x,n,m)  for(int x=n;x<(m);x++)

int r,c,k;
int row=3,col=3;
int arr[100][100];
int ans = 0;

void cal(){
    int temp_arr[100][100] = {0,};
    int new_col = 0;
    FOR(i,0,row){
        map<int,int> m;
        vector<pair<int,int>> v;
        
        FOR(j,0,col){
            if(arr[i][j]==0) continue;
            m[arr[i][j]]++;
        }
        
        for(auto it=m.begin(); it!=m.end(); it++)
            v.push_back(make_pair(it->second, it->first));
        
        sort(v.begin(), v.end());
        for(int j=0; j<v.size(); j++){
            temp_arr[i][j*2] = v[j].second;
            temp_arr[i][j*2+1] = v[j].first;
        }
        new_col = max(new_col,int(v.size())*2);
    }
    col = new_col;
    memmove(arr,temp_arr,sizeof(temp_arr));
}

void rot(){
    int temp_arr[100][100];
    FOR(i,0,100) FOR(j,0,100) temp_arr[i][j] = arr[j][i];
    memmove(arr,temp_arr,sizeof(arr));
    
    int temp = row;
    row = col;
    col = temp;
}

int main() {
    cin >> r >> c >> k;
    
    FOR(i,0,3) FOR(j,0,3) cin >> arr[i][j];
    
    while(1){
        if(arr[r-1][c-1] == k) break;
        
        if(row>=col){
            cal();
        }
        else{
            rot();
            cal();
            rot();
        }
        ans++;
        if(ans>100){
            ans = -1;
            break;
        }
    }
    
    cout << ans;
    return 0;
}
