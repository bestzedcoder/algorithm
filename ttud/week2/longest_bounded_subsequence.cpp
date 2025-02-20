/*
Description
Given a sequence of positive integers a = a
1, a2, . . ., an. A subsequence of a is defined to be a sequence of consecutive elements ai, ai+1, . . ., aj (1 <= i <= j <= n). 
The weight of a subsequence is the sum of its elements. Given a positive integer Q. A subsequence is said to be feasible if the weight is less than or equal to Q.
Find a feasible subsequence such that the number of elements of that subsequence is maximal.
Input
Line 1: contains two positive integers n and Q (1 <= n <= 10^6, 1 <= Q <= 100000)
Line 2: contains a1, a2, . . ., an (1 <= ai <= 10000).
Output
Write the number of elements of the subsequence found, or write -1 if no such subsequence exists.
Example
Input
10 40
19 2 7 6 9 1 17 19 8 4 
Output
5
*/

#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,Q; cin>>n>>Q;
    int a[n]; for(int i = 0 ; i < n ; i++) cin>>a[i];
    int prefixSum[n+1];
    prefixSum[0] = 0;
    for(int i = 1 ; i <= n ; i++) prefixSum[i] = prefixSum[i-1] + a[i-1];
    int lengthMax = 0 ;
    for(int i = 0 ; i < n ; i++) {
        int l = i , r = n - 1;
        while(l <= r) {
            int mid = l + (r - l)/2;
            int ans = prefixSum[mid + 1] - prefixSum[i];
            if(ans == Q) {
                lengthMax = max(lengthMax , mid - i + 1);
                break;
            } else if(ans < Q) {
                lengthMax = max(lengthMax , mid - i + 1);
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }
    if(lengthMax) cout<<lengthMax;
    else cout<<-1;
    return 0;
} 