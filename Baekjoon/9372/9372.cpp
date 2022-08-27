#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

#define FOR(x,n,m)  for(int x=n;x<(m);x++)

typedef struct A{
    int f,t;
    A(int F, int T) : f(F), t(T) {}
};

int n,m;
vector<A> v;

int uf[1001];

int find(int a){
    if(uf[a] < 0) return a;
    return uf[a] = find(uf[a]);
}

bool merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a==b) return false;
    uf[b] = a;
    return true;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int ans = 0;
        memset(uf,-1,sizeof(uf));
        v.clear();
        
        cin >> n >> m;
        
        FOR(i,0,m){
            int from,to; cin >> from >> to;
            v.push_back(A(from,to));
        }
        
        FOR(i,0,m){
            if(merge(v[i].f, v[i].t)){
                if(++ans == n-1) break;
            }
        }
        
        cout << ans << endl;
    }
}
