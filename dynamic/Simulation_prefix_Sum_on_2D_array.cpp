/*
Bài toán: Simulation prefix Sum on 2D array

Mô tả bài toán
Cho một bảng gồm n hàng (1, 2, ..., n) và m cột (1, 2, ..., m). Mỗi ô (i, j) trong bảng chứa một số nguyên không âm a(i,j).
Bạn cần xử lý một danh sách các truy vấn (r1, c1, r2, c2), mỗi truy vấn yêu cầu tính tổng các phần tử trong bảng con từ 
hàng r1 đến r2 và từ cột c1 đến c2.

Dữ liệu vào
Dòng 1: Chứa hai số nguyên n và m (1 ≤ n, m ≤ 1000).
Dòng i+1 (i = 1, 2, ..., n): Chứa các phần tử của hàng thứ i trong bảng.
Dòng n+2: Chứa số nguyên dương Q (1 ≤ Q ≤ 100000), là số lượng truy vấn.
Dòng q+n+2 (q = 1, 2, ..., Q): Chứa 4 số nguyên r1, c1, r2, c2 (1 ≤ r1 ≤ r2 ≤ n, 1 ≤ c1 ≤ c2 ≤ m),mô tả truy vấn.
Dữ liệu ra
Với mỗi truy vấn, in ra một dòng chứa tổng các phần tử trong bảng con từ (r1, c1) đến (r2, c2).
Ví dụ
Dữ liệu vào
3 4
1 1 0 1 
1 1 1 0 
0 1 0 0 
3
2 3 3 4
1 3 3 4
2 2 3 4
Dữ liệu ra
1
2
3
*/

/*
Node: công thức mảng cộng dồn 2 chiều

prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1] + a[i][j];

*/

#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,m; cin>>n>>m;
    int a[n + 1][m + 1];
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= m ; j++) {
            cin>>a[i][j];
        }
    }
    int prefixSum[n+1][m+1];
    for(int i = 0 ; i <= n ; i++) prefixSum[i][0] = 0;
    for(int i = 0 ; i <= m ; i++) prefixSum[0][i] = 0;

    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= m ; j++) {
            prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1] + a[i][j];
        }
    }

    int T; cin>>T;
    while(T--) {
        int r1,c1,r2,c2; cin>>r1>>c1>>r2>>c2;
        cout<<prefixSum[r2][c2] - prefixSum[r2][c1 - 1] - prefixSum[r1-1][c2] + prefixSum[r1-1][c1-1]<<endl;
    }
}
