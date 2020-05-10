#include <iostream>
#include <string.h>
using namespace std;

#define FOR(x,n,m)  for(int x=n;x<(m);x++)

int n;
int arr[20][20];
int ans = -1;

void move(int x, int y, int d1, int d2){
    if(x+d1+d2>=n || y+d1>=n || y-d2<0) return;
    
    bool eat[101];
    memset(eat,false,sizeof(eat));
    
    int num=0;
    
    FOR(i,0,d1){
        if(eat[arr[x+i][y+i]]) return;
        eat[arr[x+i][y+i]] = true;
        num++;
    }
    
    FOR(i,0,d2){
        if(eat[arr[x+d1+i][y+d1-i]]) return;
        eat[arr[x+d1+i][y+d1-i]] = true;
        num++;
    }
    
    FOR(i,0,d1){
        if(eat[arr[x+d1+d2-i][y+d1-d2-i]]) return;
        eat[arr[x+d1+d2-i][y+d1-d2-i]] = true;
        num++;
    }
    
    FOR(i,0,d2){
        if(eat[arr[x+d2-i][y-d2+i]]) return;
        eat[arr[x+d2-i][y-d2+i]] = true;
        num++;
    }
    
    ans = max(ans,num);
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        ans = -1;
        cin >> n;
        FOR(i,0,n) FOR(j,0,n) cin >> arr[i][j];

        FOR(i,0,n) FOR(j,0,n) FOR(k,1,n) FOR(l,1,n) move(i,j,k,l);
            
        cout << "#" << test_case << " " << ans << endl;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
