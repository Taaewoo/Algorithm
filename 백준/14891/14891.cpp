#include <iostream>
#include <deque>
#include <vector>
using namespace std;

#define FOR(x,n,m)  for(int x=n;x<(m);x++)

deque<int> dq[4];
vector<pair<int,int>> com;

void command(){
    FOR(i,0,com.size()){
        int n = com[i].first, d = com[i].second;
        
        vector<pair<int,int>> v;
        v.push_back(make_pair(n, d));
        
        for(int j=n; j<3; j++){
            if(dq[j][2] == dq[j+1][6]) break;
            
            v.push_back(make_pair(j+1,d*(-1)));
            d*=-1;
        }
        
        d = com[i].second;
        for(int j=n; j>0; j--){
            if(dq[j][6] == dq[j-1][2]) break;
            
            v.push_back(make_pair(j-1,d*(-1)));
            d*=-1;
        }
        
        FOR(j,0,v.size()){
            if(v[j].second==1){
                int temp = dq[v[j].first].back();
                dq[v[j].first].pop_back();
                dq[v[j].first].push_front(temp);
            }
            else{
                int temp = dq[v[j].first].front();
                dq[v[j].first].pop_front();
                dq[v[j].first].push_back(temp);
            }
        }
    }
}

int main() {
    
    int k;
    
    FOR(i,0,4){
        string s;
        cin >> s;
        FOR(j,0,s.size()) dq[i].push_back(s[j] - '0');
    }
    
    cin >> k;
    FOR(i,0,k){
        int n, d; cin >> n >> d;
        com.push_back(make_pair(n-1,d));
    }
    
    command();
    
    int ans = 0;
    if(dq[0][0] == 1) ans+=1;
    if(dq[1][0] == 1) ans+=2;
    if(dq[2][0] == 1) ans+=4;
    if(dq[3][0] == 1) ans+=8;
    cout << ans;
    
    return 0;
}
