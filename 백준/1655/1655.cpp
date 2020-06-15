#include <iostream>
#include <queue>
using namespace std;

#define FOR(x,n,m)  for(int x=n;x<(m);x++)

priority_queue<int, vector<int>> max_h;
priority_queue<int, vector<int>, greater<int>> min_h;
int n;

int main() {
    cin >> n;
    FOR(i,0,n){
        int num; scanf("%d", &num);
        
        if(max_h.size() > min_h.size()) min_h.push(num);
        else max_h.push(num);
        
        if(!max_h.empty() && !min_h.empty() && max_h.top() > min_h.top()){
            int max_temp = max_h.top();
            int min_temp = min_h.top();
            max_h.pop(); min_h.pop();
            
            max_h.push(min_temp);
            min_h.push(max_temp);
        }
        
        printf("%d\n", max_h.top());
    }
    
    return 0;
}
