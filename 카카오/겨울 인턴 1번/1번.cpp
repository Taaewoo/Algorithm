#include <iostream>
#include <vector>
using namespace std;

#define FOR(x,n,m)  for(int x=n;x<(m);x++)

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<vector<int>> arr(board[0].size());
    
    vector<int> b;
    
    FOR(i,0,board[0].size()){
        for(int j=int(board.size())-1; j>=0; j--){
            if(board[j][i]==0) continue;
            
            arr[i].push_back(board[j][i]);
        }
    }
    
    FOR(i,0,moves.size()){
        if(arr[moves[i]-1].size()==0) continue;
        
        int t = arr[moves[i]-1].back();
        arr[moves[i]-1].pop_back();
        
        if(b.size()==0) b.push_back(t);
        else{
            if(b.back() == t){
                b.pop_back();
                answer+=2;
            }
            else b.push_back(t);
        }
    }
    
    return answer;
}

int main(int argc, char** argv)
{
    vector<vector<int>> board = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
    
    vector<int> moves = {1,5,3,5,1,2,1,4};
    
    cout << solution(board,moves);
    
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
