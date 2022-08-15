#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

#define FOR(x,n,m)  for(int x=n;x<(m);x++)

map<string,int> m;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    
    FOR(i,0,gems.size())
        if(m.find(gems[i]) == m.end()) m[gems[i]]++;
    
    
    map<string,int> cur_m;
    int s=0,e=0,sA=0,eA=100001;
    bool check = false;
    while(1){
        if(check){
            if(cur_m[gems[s]]==1) cur_m.erase(gems[s++]);
            else cur_m[gems[s++]]--;
        }
        else if(e==gems.size()) break;
        else cur_m[gems[e++]]++;
        
        if(m.size() == cur_m.size()){
            if((eA - sA) > (e - s)){
                sA = s;
                eA = e;
            }
            check = true;
        }
        else check = false;
        
    }
    answer.push_back(++sA);
    answer.push_back(eA);
    
    return answer;
}

int main() {
    vector<string> str = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
    solution(str);
}
