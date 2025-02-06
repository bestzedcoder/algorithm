/*
Bài toán: Max Subsequence No 2 adjacent elements selected

Đề bài:

Cho một dãy số nguyên dương (a_1, a_2, \ldots, a_n). Hãy chọn một tập con của các phần tử sao cho tổng các phần tử là lớn nhất và không có hai phần tử liền kề nào được chọn.

Đầu vào:

Dòng 1: chứa một số nguyên dương (n) (1 <= (n) <= 100000)
Dòng 2: chứa các số (a_1, a_2, \ldots, a_n) (1 <= (a_i) <= 1000)
Đầu ra:

In ra tổng của các phần tử của dãy con đã chọn sao cho tổng là lớn nhất và không có hai phần tử liền kề nào được chọn.

Ví dụ:

Đầu vào:

Code
5
2 5 4 6 7
Đầu ra:

Code
13
 
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    int a[n];
    for(int i = 0 ; i < n ; i++) cin>>a[i];
    if(n == 1) {
        cout<<a[0];
        return 0;
    }
    int dp[n];
    dp[0] = a[0];
    dp[1] = max(dp[0] , a[1]);
    for(int i = 2 ; i < n ; i++) {
        dp[i] = max(dp[i-1] , dp[i-2] + a[i]);
    }
    cout<<dp[n-1];
    return 0;
}