/*
Bài toán: CBUS

Mô tả
Có n hành khách 1, 2, ..., n. Hành khách i muốn di chuyển từ điểm i đến điểm i + n (i = 1, 2, ..., n).
Có một chiếc xe buýt nằm tại điểm 0 và có k chỗ ngồi để vận chuyển hành khách (nghĩa là tại bất kỳ thời điểm nào, trên xe buýt có tối đa k hành khách).
Bạn được cung cấp ma trận khoảng cách c trong đó c(i, j) là khoảng cách di chuyển từ điểm i đến điểm j (i, j = 0, 1, ..., 2n). 
Hãy tính toán lộ trình ngắn nhất cho xe buýt, phục vụ n hành khách và trở về điểm 0.

Đầu vào
Dòng 1 chứa n và k (1 ≤ n ≤ 11, 1 ≤ k ≤ 10).
Dòng i+1 (i = 1, 2, ..., 2n+1) chứa dòng thứ (i−1) của ma trận c (các hàng và cột được đánh số từ 0, 1, 2, ..., 2n).

Đầu ra
Dòng duy nhất chứa độ dài của lộ trình ngắn nhất.
Ví dụ
Đầu vào
3 2
0 8 5 1 10 5 9
9 0 5 6 6 2 8
2 2 0 3 8 7 2
5 3 4 0 3 2 7
9 6 8 7 0 9 10
3 8 10 6 5 0 2
3 4 4 5 2 2 0
Đầu ra
25
*/

#include<bits/stdc++.h>
using namespace std;

int n,k;
int w[30][30];
bool visited[30];
int x[30];
int d = 0 , result = INT_MAX , Cmin = INT_MAX , card = 0;


void initial() {
    cin>>n>>k;
    for(int i = 0 ; i < n*2 + 1 ; i++) {
        for(int j = 0 ; j < n*2 + 1 ; j++){
            cin>>w[i][j];
            if(i!=j) Cmin = min(Cmin , w[i][j]);
        }
    }
    memset(visited , false , sizeof(visited));
}
bool check(int i) {
    if(visited[i]) return false;
    if(i > n) {
        if(!visited[i-n]) return false;
    } else {
        if(card + 1 > k) return false;
    }
    return true;
}

void CBUS(int u) {
    for(int i = 1 ; i <= n*2 ; i++) {
        if(check(i)) {
            x[u] = i;
            visited[i] = true;
            d += w[x[u-1]][x[u]];
            if(i > n) 
                card -=1;
             else card +=1;
            if(u == 2*n ) result = min(result , d + w[x[u]][0]);
            else {
                if(Cmin*(2*n - u + 1) + d <= result) CBUS(u+1);
            }
            visited[i] = false;
            d -= w[x[u-1]][x[u]];
            if(i > n) 
                card +=1;
             else card -=1;
        }
    }
}

int main() {
    initial();
    CBUS(1);
    cout<<result;
    return 0;
}