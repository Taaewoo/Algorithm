#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

#define FOR(x,n,m) for(int x=n; x<(m); x++)

struct E{
    int a,b,c;
    E(int A, int B, int C) : a(A), b(B), c(C) {}
    bool operator <(const E& e) {return c < e.c;}
};

int n,m;
vector<E> v;
int uf[100000];

int find(int a){
    if(uf[a]==-1) return a;
    else return uf[a] = find(uf[a]);
}

bool merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a==b) return false;
    uf[b] = a;
    return true;
}

int main()
{
    cin >> n >> m;

    FOR(i,0,m){
        int a,b,c; cin >> a >> b >> c;
        v.push_back(E(a-1,b-1,c));
    }

    sort(v.begin(), v.end());
    memset(uf,-1,sizeof(uf));
    
    int sum = 0, cnt = 0;
    FOR(i,0,m){
        if(merge(v[i].a, v[i].b)){
            sum += v[i].c;
            if(++cnt == n-2) break;
        }
    }

    cout << sum;

    return 0;
}
