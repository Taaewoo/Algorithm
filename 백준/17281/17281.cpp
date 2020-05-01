#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FOR(x,n,m)  for(int x=n;x<(m);x++)

int n;
int arr[50][9];
vector<int> per;
int ans = 0;

void cal(){
    int out = 0;
    int player = 0;
    int score=0;
    int roo[3] = {-1,-1,-1};
    while(out<n*3){
        int inn = out/3;
        int cur = arr[inn][per[player%9]];
        
        if(cur==0){
            player++;
            out++;
            if(out%3==0) FOR(i,0,3) roo[i] = -1;
            continue;
        }
        else if(cur==4){
            FOR(i,0,3) if(roo[i]!=-1) score++;
            score++;
            player++;
            FOR(i,0,3) roo[i] = -1;
            continue;
        }
        
        for(int i=2; i>=0; i--){
            if(roo[i]==-1) continue;
            
            if(i+cur>=3) score++;
            else roo[i+cur] = player;
            
            roo[i] = -1;
        }
        roo[cur-1] = player;
        player++;
    }
    
    ans = max(ans,score);
}

int main() {
    cin >> n;
    
    FOR(i,0,n) FOR(j,0,9) cin >> arr[i][j];
        
    FOR(i,0,9) per.push_back(i);
        
    do{
        if(per[3]!=0) continue;
        
        cal();
    }while(next_permutation(per.begin(), per.end()));
    
    cout << ans;
    
    return 0;
}
