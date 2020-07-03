#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;

#define FOR(x,n,m)  for(int x=n;x<(m);x++)

vector<string> split(string s){
    vector<string> sv;
    
    char cs[1001];
    strcpy(cs,s.c_str());
    
    char* tok3 = strtok(cs,"-*+");
    while(tok3!=NULL){
        sv.push_back(tok3);
        tok3 = strtok(NULL,"-*+");
    }
    
    return sv;
}

vector<string> cal(vector<string> v, int op){
    vector<string> st;
    
    string oper;
    if(op == 0) oper = "+";
    else if(op == 1) oper = "-";
    else if(op == 2) oper = "*";
    
    for(int i=0; i<v.size(); i++){
        if(v[i].compare(oper) == 0){
            long long res = -1;
            if(oper.compare("+") == 0)
                res = atoll(st.back().c_str()) + atoll(v[i+1].c_str());
            else if(oper.compare("-") == 0)
                res = atoll(st.back().c_str()) - atoll(v[i+1].c_str());
            else if(oper.compare("*") == 0)
                res = atoll(st.back().c_str()) * atoll(v[i+1].c_str());
            
            st.pop_back();
            st.push_back(to_string(res));
            i++;
        }
        else st.push_back(v[i]);
    }
    return st;
}

long long solution(string exp) {
    long long answer = 0;
    
    vector<char> opers;
    FOR(i,0,exp.size())
    if(exp[i]=='+' || exp[i]=='*' || exp[i]=='-') opers.push_back(exp[i]);
    
    vector<string> numbers = split(exp);
    
    vector<string> expV;
    FOR(i,0,opers.size()){
        string temp;
        temp.push_back(opers[i]);
        expV.push_back(numbers[i]);
        expV.push_back(temp);
    }
    expV.push_back(numbers[numbers.size()-1]);
    
    vector<int> per;
    FOR(i,0,3) per.push_back(i);

    do{
        vector<string> tempV = expV;
        FOR(i,0,3) tempV = cal(tempV,per[i]);
                
        answer = max(answer,abs(atoll(tempV[0].c_str())));
    }while(next_permutation(per.begin(), per.end()));
    
    return answer;
}

int main() {
    cout << solution("100-200*300-500+20");
}
