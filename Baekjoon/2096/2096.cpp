#include <iostream>
#include <string.h>
using namespace std;

#define FOR(x,n,m)  for(int x=n;x<(m);x++)

int n;
int arr[100001][4];
int dp[5];

int main() {
    cin >> n;
    FOR(i,1,n+1) FOR(j,1,4) cin >> arr[i][j];
    
    dp[1] = arr[n][1];
    dp[2] = arr[n][2];
    dp[3] = arr[n][3];
    
    for(int i=n-1; i>=0; i--){
        int temp[5];
        for(int j=1; j<=3; j++){
            temp[j] = max(dp[j-1], dp[j]);
            temp[j] = max(temp[j], dp[j+1]);
            temp[j] += arr[i][j];
        }
        for(int j=1; j<=3; j++) dp[j] = temp[j];
    }
    int max_n = dp[2];
    
    dp[0] = 987654321;
    dp[1] = arr[n][1];
    dp[2] = arr[n][2];
    dp[3] = arr[n][3];
    dp[4] = 987654321;
    
    for(int i=n-1; i>=0; i--){
        int temp[5];
        for(int j=1; j<=3; j++){
            temp[j] = min(dp[j-1], dp[j]);
            temp[j] = min(temp[j], dp[j+1]);
            temp[j] += arr[i][j];
        }
        for(int j=1; j<=3; j++) dp[j] = temp[j];
    }
    
    int min_n = dp[2];
    
    cout << max_n << " " << min_n;
}
