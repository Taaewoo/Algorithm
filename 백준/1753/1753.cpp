#include <iostream>
#include <queue>
#include <vector>

#define FOR(x,a,b) for(int x=a; x<b; x++)

using namespace std;

struct E{
    int u,v,w;
    E(int U, int V, int W) : u(U), v(V), w(W) {}
};

struct V{
    int n,d;
    V(int N, int D) : n(N), d(D) {}
};

struct cmp{
    bool operator() (const V& a, V& b){
        return a.d > b.d;
    }
};

int v,e,k;
vector<E> adj[20000];
int dist[20000];
bool visit[20000];
priority_queue<V, vector<V>, cmp> pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> v >> e >> k;
    
    FOR(i,0,v) dist[i] = 987654321;
    
    FOR(i,0,e){
        int uu,vv,ww; cin >> uu >> vv >> ww;
        adj[uu-1].push_back(E(uu-1,vv-1,ww));
    }
    
    dist[k-1] = 0;
    pq.push(V(k-1,0));
    while(!pq.empty()){
        V cur = pq.top(); pq.pop();
        
        if(visit[cur.n]) continue;
        
        visit[cur.n] = true;
        
        for(auto ee : adj[cur.n]){
            int next = ee.v;
            if(dist[next] <= cur.d + ee.w) continue;
            
            dist[next] = cur.d + ee.w;
            pq.push(V(next,dist[next]));
        }
    }
    
    FOR(i,0,v) cout << (dist[i]==987654321 ? "INF" : to_string(dist[i])) << endl;
    
    return 0;
}
