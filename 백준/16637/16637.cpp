#include <iostream>
using namespace std;

#define FOR(x,n,m)  for(int x=n;x<(m);x++)

int n;
string s;
int ans = -987654321;

int oper(int num1, char op, int num2){
    if(op=='+') return num1+num2;
    else if(op=='*') return num1*num2;
    else return num1-num2;
}

void dfs(int x, int sum){
    if(x==n-1){
        ans = max(ans,sum);
        return;
    }
    
    dfs(x+2, oper(sum,s[x+1],s[x+2]-'0'));
    
    if(x+4<n) dfs(x+4, oper(sum,s[x+1], oper(s[x+2]-'0',s[x+3],s[x+4]-'0')));
}

int main() {
    cin >> n;
    cin >> s;
    
    dfs(0,s[0]-'0');
    
    cout << ans;
    
    return 0;
}
