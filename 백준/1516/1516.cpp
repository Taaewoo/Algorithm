#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define FOR(x,n,m)  for(int x=n;x<(m);x++)

int n;
int build_t[500];
vector<int> next_n[500];
int indegree[500];
int result[500];

int main() {
    cin >> n;
    
    FOR(i,0,n){
        int temp; cin >> temp;
        build_t[i] = temp;
        while(1){
            cin >> temp;
            if(temp == -1) break;
            
            next_n[temp-1].push_back(i);
            indegree[i]++;
        }
    }
    
    queue<int> q;
    FOR(i,0,n){
        if(indegree[i]==0){
            q.push(i);
            result[i] = build_t[i];
        }
    }
    
    FOR(i,0,n){
        if(q.empty()) break;
        
        int cur = q.front(); q.pop();
        for(auto e : next_n[cur]){
            result[e] = max(build_t[e] + result[cur], result[e]);
            if(--indegree[e] == 0) q.push(e);
        }
    }
    
    FOR(i,0,n) cout << result[i] << endl;
}
