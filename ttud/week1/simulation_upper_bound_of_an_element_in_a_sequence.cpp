/*
Description
Given a sequence of n positive integers a1, a2, ..., an. Perform a sequence of queries of type:
next k: return the smallest element of the given sequence that is greater than k. Return -1 if no such element is found.

Input
Line 1: contains n (1 <= n <= 100000)
Line 2: contains a1, a2, ..., an (1 <= ai <= 1000000)
Each subsequent line contains a query of format above. The input is terminated with a line containing #

Output
Write in each line the result of the corresponding query.
 
Example
Input
5
4 8 2 3 7 
next 2
next 7
next 9
next 6
next 1
#

Output 
3
8
-1
7
2
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    int a[n];
    for(int i = 0 ; i < n ; i++) cin>>a[i];
    sort(a , a + n);
    while(true) {
        string s; cin>>s;
        if(s == "#") break;
        else {
            int u; cin>>u;
            if(a[n-1] <= u) cout<<-1<<"\n";
            else {
                int l = 0 , r = n - 1;
                while(l < r) {
                    int mid = l + (r - l) /2;
                    if(a[mid] == u) l = mid + 1;
                    else if(a[mid] < u) l = mid + 1;
                    else if (a[mid] > u) r = mid;
                }
                cout<<a[r]<<'\n';
            }
        }
    }
}