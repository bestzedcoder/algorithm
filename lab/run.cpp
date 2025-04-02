#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return (a.second > b.second) || (a.second == b.second && a.first > b.first);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    
    vector<pair<int, int>> jobs(n);
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].first >> jobs[i].second;
    }
    
    // Sắp xếp công việc theo lợi nhuận giảm dần
    sort(jobs.begin(), jobs.end(), cmp);
    
    int maxDeadline = 0;
    for (auto j : jobs) maxDeadline = max(maxDeadline, j.first);

    vector<bool> visited(maxDeadline + 1, false);
    int totalProfit = 0;

    for (auto job : jobs) {
        for (int d = job.first; d > 0; d--) {
            if (!visited[d]) {
                visited[d] = true;
                totalProfit += job.second;
                break;
            }
        }
    }
    
    cout << totalProfit;
    return 0;
}
