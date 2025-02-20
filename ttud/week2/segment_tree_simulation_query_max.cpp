/*
Description
Given a sequence of positive integers a1, a2, . . ., an. 
Perform a sequence of actions of following types:
update  i  v : assign ai = v
get-max  i  j : return the maximum value of the subsequence ai, ai+1, . . ., aj

Input
Line 1: contains a positive integer n (1 <= n <= 100000)
Line 2: contains a1, a2, . . ., an. (1 <= ai <= 10000)
Line 3: contains a positive integer m (1 <= m <= 100000) which is the number of actions
Line i + 3 (i = 1, 2, . . ., m): contains an action described above
Output
Write in each line the result of the corresponding action of type get-max
Example
Input
10
1 10 9 7 1 4 2 4 8 10 
5
get-max 5 8
get-max 5 9
get-max 3 8
update 9 20
get-max 4 10

Ouput
4
8
9
20
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> mst(100001*4);

void build(int arr[] ,int l ,int r ,int id) {
    if(r == l) {
        mst[id] = arr[l];
        return;
    }
    int mid = l + (r - l)/2;
    build(arr,l,mid,id*2);
    build(arr,mid+1,r,id*2+1);
    mst[id] = max(mst[id*2] , mst[id*2+1]);
}

void update(int l ,int r ,int id ,int index ,int value)
{
    if(index <l || index > r) return;
    if(l==r) {
        mst[id] = value;
        return;
    }
    int mid = l + (r - l)/2;
    update(l,mid,id*2,index,value);
    update(mid+1,r,id*2+1,index,value);
    mst[id] = max(mst[id*2] , mst[id*2+1]);
}

int getMax(int l ,int r ,int id ,int u ,int v) {
    if(v < l || u > r) return -1;
    if( l >= u  && v >= r) return mst[id];
    int mid = l + (r - l)/2;
    int max1 = getMax(l,mid,id*2,u,v);
    int max2 = getMax(mid+1,r,id*2+1,u,v);
    return max(max1 , max2);
}

int main() {
    int n; cin>>n;
    int arr[n+1];
    for(int  i = 1 ; i <= n ; i++) {
        cin>>arr[i];
    }
    build(arr , 1 , n , 1 );
    int query; cin>>query;
    while(query--) {
        string s; cin>>s;
        if(s == "get-max") {
            int u,v; cin>>u>>v;
            cout<<getMax(1,n,1,u,v)<<endl;
        }
        if(s == "update") {
            int index,value; cin>>index>>value;
            update(1,n,1,index,value);
        }
    }
}