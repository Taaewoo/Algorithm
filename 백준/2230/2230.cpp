#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(x,n,m) for(int x=n; x<(m); x++)

int n, m;
int arr[100000];

int main()
{
    cin >> n >> m;

    FOR(i,0,n) cin >> arr[i];

    int s=0,e=0,minN=2000000000;

    sort(arr,arr+n);

    while(1){
        if(arr[e]-arr[s] < m) e++;
        else if(e >= n) break;
        else minN = min(arr[e]-arr[s++], minN);
    }

    cout << minN;

    return 0;
}
