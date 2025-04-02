#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ; i++) {
        cin>> arr[i];
    }
    int dp[n + 1] , result = -1;
    dp[0] = 0;
    for(int i = 1 ; i <= n ; i++ ) {
        if(arr[i-1]%2 == 0) result = max(result , arr[i-1]);
        if(dp[i-1] >=0 ) {
            dp[i] = dp[i-1] +arr[i-1];
        } else dp[i] = arr[i - 1];
        result = dp[i] % 2 == 0 ? max(result , dp[i]) : result;
    }
    if(result != -1)
    cout<<result;
    else cout<<"NOT_FOUND";
}