/*
Description
Given a sequence of n integers a0,. . .,an-1. 
We denote rmq(i,j) the minimum element of the sequence ai, ai+1, . . .,aj. 
Given m pairs (i1, j1),. . .,(im, jm), compute the sum Q = rmq(i1,j1) + . . . + rmq(im, jm )
Input
Line 1: n (1 <=  n <= 10^6)
Line 2: a0, . . . ,an-1 ( 1  <=  ai <= 10^6)
line 3: m (1  <= m <= 10^6)
Line k+3 (k=1, . . ., m): ik, jk  (0  <=  ik < jk < n)
Output
Write the value Q
Example
Input
16
2 4 6 1 6 8 7 3 3 5 8 9 1 2 6 4
4
1 5
0 9
1 15
6 10

Output
6
*/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000001;
vector<int> st(maxn*4 + 4);

void build(int arr[] , int l , int r , int id) {
    if(l==r) {
        st[id] = arr[l];
        return ;
    }
    int mid = l + ( r - l )/2;
    build(arr , l , mid , id*2);
    build(arr , mid + 1 , r , id*2 + 1);
    st[id] = min(st[id*2] , st[id*2+1]);
}

int getMin(int arr[] , int l , int r , int id , int u , int v) {
    if(l > v || r < u) return INT_MAX;
    if(l >= u && r<= v) return st[id];
    int mid = l + ( r - l )/2;
    int min1 = getMin(arr , l , mid , id*2 , u , v);
    int min2 = getMin(arr , mid + 1 , r , id*2 + 1 , u , v);
    return min(min1 , min2);
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ; i++) cin>>arr[i];
    build(arr , 0 , n - 1 , 1);
    int T; cin>>T;
    int result = 0;
    while(T--) {
        int u,v ; cin>>u>>v;
        result += getMin(arr, 0 , n - 1, 1 , u , v);
    }
    cout<<result;
    return 0;
}