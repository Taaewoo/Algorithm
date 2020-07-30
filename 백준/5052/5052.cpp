#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define FOR(x,n,m) for(int x=n; x<(m); x++)

bool cmp(const string& a, const string& b){
    return a.size() < b.size();
}

int main()
{
   int t; cin >> t;
   while(t--){
        int n; cin >> n;
        unordered_map<string,bool> m;
        string arr[10000];

        FOR(i,0,n) cin >> arr[i];

        sort(arr,arr+n,cmp);
       
        bool check = true;
        FOR(i,0,n){
            FOR(j,1,arr[i].size()+1){
                string temp = arr[i].substr(0,j);
                if(m.find(temp) != m.end()){
                    check = false;
                    break;
                }
            }
            if(check) m[arr[i]] = true;
            else break;
        }

        if(check) cout << "YES" << endl;
        else cout << "NO" << endl;
   }

    return 0;
}
