/*
Bài toán: Segment Tree Simulation

Mô tả:
Cho một dãy số nguyên dương (a_1, a_2, \ldots, a_n). Thực hiện một loạt các hành động theo các loại sau:
update i v: gán (a_i = v)
get-max i j: trả về giá trị lớn nhất của dãy con (a_i, a_{i+1}, \ldots, a_j)

Đầu vào:
Dòng 1: chứa một số nguyên dương (n) (1 <= (n) <= 100000)
Dòng 2: chứa các số (a_1, a_2, \ldots, a_n) (1 <= (a_i) <= 10000)
Dòng 3: chứa một số nguyên dương (m) (1 <= (m) <= 100000), là số lượng các hành động
Dòng (i + 3) (với (i = 1, 2, \ldots, m)): chứa một hành động được mô tả ở trên

Đầu ra:
In ra kết quả của mỗi hành động loại get-max
Ví dụ:

Đầu vào:
10
1 10 9 7 1 4 2 4 8 10 
5
get-max 5 8
get-max 5 9
get-max 3 8
update 9 20
get-max 4 10

Đầu ra:
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