#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define FOR(x,n,m)  for(int x=n;x<(m);x++)

int lp = 10, rp = 12;
int pos[13][2] = {{},
    {0,0},{0,1},{0,2},
    {1,0},{1,1},{1,2},
    {2,0},{2,1},{2,2},
    {3,0},{3,1},{3,2}
};

void move(int number, string h, string &answer){
    answer += h;
    if(h.compare("L") == 0) lp = number;
    else rp = number;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    FOR(i,0,numbers.size()){
        int number = numbers[i];
        
        if(number == 1 || number == 4 || number == 7) move(number, "L", answer);
        else if(number == 3 || number == 6 || number == 9) move(number, "R", answer);
        else{
            if(number == 0) number = 11;
            
            int ld = abs(pos[number][0] - pos[lp][0]) + abs(pos[number][1] - pos[lp][1]);
            int rd = abs(pos[number][0] - pos[rp][0]) + abs(pos[number][1] - pos[rp][1]);
            
            if(ld < rd) move(number, "L", answer);
            else if(ld > rd) move(number, "R", answer);
            else{
                if(hand.compare("left") == 0) move(number, "L", answer);
                else move(number, "R", answer);
            }
        }
    }
    return answer;
}

int main() {
    vector<int> num = {7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2};
    string hand = "left";
    cout << solution(num, hand);
}
