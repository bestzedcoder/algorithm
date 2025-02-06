/*
bải toán: Longest Path on a Tree

Đề bài: Đề bài

Cho một cây vô hướng G = (V, E) trong đó V = {1, …, N} là tập các đỉnh. Mỗi cạnh (u, v) ∈ E có trọng số w(u, v). 
Độ dài của một đường đi được định nghĩa là tổng trọng số của các cạnh trên đường đi đó. Hãy tìm đường đi đơn dài nhất trên cây G.

Dữ liệu vào
Dòng 1: Số nguyên dương N (1 ≤ N ≤ 10⁵).
Dòng thứ i+1 (i = 1, …, N-1): Ba số nguyên dương u, v, w biểu diễn cạnh nối giữa đỉnh u và v có trọng số w (1 ≤ w ≤ 100).

Dữ liệu ra
In ra độ dài của đường đi dài nhất trong cây.
Ví dụ

Dữ liệu vào
6
1 3 3
1 6 2
2 6 5
4 5 2
4 6 1
Dữ liệu ra
10
*/

/*
ý tưởng dùng dfs từ 1 đỉnh bất kỳ để tìm đỉnh xa nhất giả sử là đỉnh A , xong dfs tìm đỉnh B xa nhất từ A
*/

#include<bits/stdc++.h>
using namespace std;

int n ,maxDist = 0 , farthestNode ;
vector<pair<int,int>> tree[100001];
bool visited[100001];
void initial() {
    cin>>n;
    for(int i = 0 ; i < n - 1 ; i++) {
        int u,v,w; cin>>u>>v>>w;
        tree[u].push_back({v,w});
        tree[v].push_back({u,w});
    }
}

void bfs(int node,int dist) {
    visited[node] = true;
    if(dist > maxDist) {
        farthestNode = node;
        maxDist = dist;
    }
    for(pair<int,int> x : tree[node]){
        if(!visited[x.first]) {
            bfs(x.first , dist+x.second);
        }
    }
}

void solve() {
    memset(visited , false , sizeof(visited));
    bfs(1 , 0);

    maxDist = 0;
    memset(visited , false , sizeof(visited));
    bfs(farthestNode , 0);
    cout<<maxDist;
}
int main() {
    ios::sync_with_stdio(0);
    initial();
    solve();
    return 0;
}