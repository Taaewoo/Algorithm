#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define FOR(x,n,m)  for(int x=n;x<(m);x++)

int n,m;
vector<int> con[1001];
int indegree[1001];
int result[1001];

int main() {
    cin >> n >> m;
    
    FOR(i,0,m){
        int temp; cin >> temp;
        
        int pre; cin >> pre;
        
        FOR(j,1,temp){
            int cur; cin >> cur;
            con[pre-1].push_back(cur-1);
            indegree[cur-1]++;
            pre = cur;
        }
    }
    
    queue<int> q;
    
    FOR(i,0,n) if(indegree[i]==0) q.push(i);
    
    FOR(i,0,n){
        if(q.empty()){
            cout << 0;
            return 0;
        }
        
        int c = q.front(); q.pop();
        result[i] = c;
        for(auto e : con[c])
            if(--indegree[e] == 0) q.push(e);
    }
    
    FOR(i,0,n) cout << result[i]+1 << endl;
}
