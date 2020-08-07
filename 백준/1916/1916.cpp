#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define FOR(x,a,b) for(int x=a; x<b; x++)

struct E{
    int f,t,c;
    E(int F, int T, int C) : f(F), t(T), c(C) {}
};

struct V{
    int num,dist;
    V(int N, int D) : num(N), dist(D) {}
};

struct cmp{
    bool operator() (V& a, V& b){
        return a.dist > b.dist;
    }
};

int n,m,s,d;
int dist[1000];
bool visit[1000];
vector<E> adj[1000];
priority_queue<V,vector<V>,cmp> pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    
    FOR(i,0,n) dist[i] = 987654321;
    
    FOR(i,0,m){
        int f,t,c; cin >> f >> t >> c;
        adj[f-1].push_back(E(f-1,t-1,c));
    }
    
    cin >> s >> d;
    
    pq.push(V(s-1,0));
    dist[s-1] = 0;
    while(!pq.empty()){
        V cur = pq.top(); pq.pop();
        
        if(visit[cur.num]) continue;
        visit[cur.num] = true;
        
        for(auto e : adj[cur.num]){
            int next = e.t;
            
            if(dist[next] <= cur.dist + e.c) continue;
            
            dist[next] = cur.dist + e.c;
            pq.push(V(next, dist[next]));
        }
    }
    
    cout << dist[d-1];
    
    return 0;
}
