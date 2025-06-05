#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;

int n,m;
int parent[maxn] , r[maxn];
vector<tuple<int,int,int>> adj;

void init() {
    cin>>n>>m;
    for(int i = 0 ; i < m ; i++) {
        int u,v,w; cin>>u>>v>>w;
        adj.push_back(make_tuple(w , u , v));
    }

    sort(adj.begin() , adj.end());

    for(int i = 0 ; i < n ; i++) {
        parent[i] = i;
        r[i] = 0;
    }
}

// DSU

int f(int u) {
    if(u != parent[u]) {
        parent[u] = f(parent[u]);
    }
    return parent[u];
}

bool un(int u,int v) {
    u = f(u), v = f(v);
    if(u == v) return false;
    if(r[u] < r[v]) swap(u,v);
    parent[v] = u;
    if(r[v] == r[u]) r[u]++;
    return true;
}

void  kruskal() {
    int result = 0;
    for(auto [w,u,v] : adj) {
        if(un(u,v)) {
            result += w;
        }
    }
    cout<<result<<endl;
    return;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    init();
    kruskal();
    return 0;
}
