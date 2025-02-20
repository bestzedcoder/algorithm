/*
Description
Given a sequence of integers a1, a2, . . ., an
. Perform a sequence of Q queries q(i,j) that returns the sum of ai, ai+1, . . ., aj.
Input
Line 1: contains a positive integer n (2 <= n <= 100000)
Line 2: contains a1, a2, ..., an. (1 <= ai <= 1000)
Line 3: contains a positive integer Q (1 <= Q <= 100000)
Line 3 + k (k = 1, 2, ..., Q): contains 2 positive integers i and j (1 <= i < j <= n) of the k
th
 query
 
Output
Write in each line, the result of the corresponding query read from the input

Example
Input
5
5 8 7 1 9 
4
1 2
1 5
1 3
4 5

Output 
13
30
20
10 
*/

#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin>>n;
    int a[n];
    for(int i = 0 ; i < n ; i++) cin>>a[i];
    int prefixSum[n+1];
    prefixSum[0] = 0;
    for(int i = 1 ; i <= n ; i++) prefixSum[i] = prefixSum[i-1] + a[i-1];
    int T; cin>>T;
    while(T--) {
        int u , v; cin>>u>>v;
        cout<<prefixSum[v] - prefixSum[u-1]<<"\n";
    }
}