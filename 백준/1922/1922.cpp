#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

#define FOR(x,n,m)  for(int x=n;x<(m);x++)

typedef struct L{
    int f,t,c;
    L(int F, int T, int C) : f(F), t(T), c(C) {}
    bool operator <(const L& l)const{ return c < l.c; }
};

int n,m;
vector<L> v;
int uf[1001];

int find_uf(int a){
    if(uf[a]==-1) return a;
    return uf[a] = find_uf(uf[a]);
}

bool merge(int a, int b){
    a = find_uf(a);
    b = find_uf(b);
    if(a==b) return false;
    uf[b] = a;
    return true;
}

int main() {
    cin >> n >> m;
    FOR(i,0,m){
        int from, to, cost;
        cin >> from >> to >> cost;
        v.push_back(L(from,to,cost));
    }
    
    sort(v.begin(), v.end());
    memset(uf,-1,sizeof(uf));
    
    int ans = 0;
    int num = 0;
    FOR(i,0,v.size()){
        if(merge(v[i].f, v[i].t)){
            ans += v[i].c;
            if(++num == n-1) break;
        }
    }
    
    cout << ans;
}
