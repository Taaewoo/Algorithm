#include <iostream>
#include <queue>
using namespace std;

#define FOR(x,n,m)  for(int x=n;x<(m);x++)

int n;
priority_queue<int,vector<int>,greater<int>> pq;

int main() {
    cin >> n;
    
    FOR(i,0,n){
        int temp; scanf("%d", &temp);
        if(temp == 0){
            if(pq.empty()) printf("0\n");
            else{
                printf("%d\n", pq.top());
                pq.pop();
            }
        }
        else{
            pq.push(temp);
        }
    }
    
    return 0;
}
