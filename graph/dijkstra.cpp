#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

int n, m;
int src, dst;
vector<vector<pair<int,int>>> adj;

void init() {
    cin >> n >> m;
    adj.assign(n, {});
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        //adj[v].push_back({u, w});  nếu là đồ thị vô hướng thì thêm dòng này
    }
    cin >> src >> dst;
}

void dijkstra(int s) {
    vector<ll> dist(n, INF);
    priority_queue<pair<ll,int>,
                   vector<pair<ll,int>>,
                   greater<pair<ll,int>>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d_u, u] = pq.top(); pq.pop();
        if (d_u != dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[v] > d_u + w) {
                dist[v] = d_u + w;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[dst] == INF) cout << -1;
    else cout << dist[dst];
    cout<<endl;
    for(int i = 0 ; i < n ; i++) {
        if(i != src) cout<<i<<" "<<dist[i]<<endl;
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt",  "r", stdin);
    freopen("output.txt", "w", stdout);

    init();
    dijkstra(src);
    return 0;
}
