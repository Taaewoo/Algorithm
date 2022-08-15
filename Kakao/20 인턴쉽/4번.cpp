#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

#define FOR(x,n,m)  for(int x=n;x<(m);x++)

typedef struct P{
    int x,y,c,d;
    P(int X, int Y, int C, int D) : x(X), y(Y), c(C), d(D) {}
};

int cost_arr[25][25];
int n, ans=987654321;
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int add_cost[4][4] = {
    {100,600,1,600},
    {600,100,600,1},
    {1,600,100,600},
    {600,1,600,100} };

int solution(vector<vector<int>> board) {
    int answer = 0;
    n = int(board.size());
    
    fill(cost_arr[0], cost_arr[25], 987654321);
    cost_arr[0][0] = 0;
    
    queue<P> q;
    
    if(board[0][1] == 0){
        cost_arr[0][1] = 100;
        q.push(P(0,1,100,1));
    }
    if(board[1][0] == 0){
        cost_arr[1][0] = 100;
        q.push(P(1,0,100,2));
    }
       
    while(!q.empty()){
        P cur = q.front(); q.pop();
        
        if(cur.x==n-1 && cur.y==n-1){
            ans = min(ans,cur.c);
            continue;
        }
        
        FOR(i,0,4){
            int nx = cur.x+dir[i][0], ny = cur.y+dir[i][1];
            
            if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
            if(board[nx][ny] == 1) continue;
            
            int nc = cur.c+add_cost[cur.d][i];
            if(cost_arr[nx][ny] < nc) continue;
            
            cost_arr[nx][ny] = nc;
            q.push(P(nx,ny,nc,i));
        }
    }
    
    answer = ans;
    return answer;
}

int main() {
    
    vector<vector<int>> vv = {{0,0,1,0},{0,0,0,0},{0,1,0,1},{1,0,0,0}};
    
    cout << solution(vv);
}
