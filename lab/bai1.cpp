/* Problem: Maze */
#include<bits/stdc++.h>
using namespace std;

int dx[] = { 1 , -1 , 0 , 0 };
int dy[] = { 0 , 0 , 1 , -1 };

void bfs(vector<vector<int>>& maze , int row , int column , int u , int v) {
    queue<pair<int,int>> q;
    bool visited[row][column] = {false};
    int dist[row][column] = {0};
    q.push({u - 1 , v - 1});
    visited[u - 1][v - 1] = true;

    while(!q.empty()) {
        pair<int,int> point = q.front();
        q.pop();
        if(point.first == 0 || point.second == 0 || point.first == row - 1 || point.second == column - 1) {
            cout<<dist[point.first][point.second] + 1;
            return;
        }
        for(int i = 0 ; i < 4 ; i++) {
            int x = point.first + dx[i];
            int y = point.second + dy[i];
            if(x >= 0 && y >= 0 && x <= row - 1 && y <= column - 1 && !visited[x][y] && !maze[x][y]) {
                visited[x][y] = true;
                dist[x][y]  = dist[point.first][point.second] + 1;
                q.push({x , y});
            }
        }
    }

    cout<<-1;
    return;
}

int main() {
    int row , column , u , v;
    cin>>row>>column>>u>>v;
    vector<vector<int>> maze(row , vector<int>(column));
    for(int i = 0 ; i < row ; i++) {
        for(int j = 0 ; j < column ; j++) {
            cin>>maze[i][j];
        }
    }

    bfs(maze , row , column , u ,v);
    return 0;
}