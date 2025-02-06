/*
Bài toán: Simulation prefix sum 1-array

Mô tả bài toán
Cho một dãy số nguyên a₁, a₂, ..., aₙ.
Bạn cần thực hiện một loạt các truy vấn (i, j), mỗi truy vấn yêu cầu tính tổng các phần tử từ aᵢ đến aⱼ.

Dữ liệu vào
Dòng 1: Chứa số nguyên dương n (2 ≤ n ≤ 100000) - số lượng phần tử trong dãy.
Dòng 2: Chứa n số nguyên a₁, a₂, ..., aₙ (1 ≤ aᵢ ≤ 1000).
Dòng 3: Chứa số nguyên dương Q (1 ≤ Q ≤ 100000) - số lượng truy vấn.
Dòng 3 + k (k = 1, 2, ..., Q): Mỗi dòng chứa hai số nguyên i và j (1 ≤ i < j ≤ n) mô tả truy vấn thứ k.
Dữ liệu ra
Với mỗi truy vấn (i, j), in ra một dòng chứa tổng các phần tử từ aᵢ đến aⱼ.

Ví dụ
Dữ liệu vào
5
5 8 7 1 9
4
1 2
1 5
1 3
4 5
Dữ liệu ra
13
30
20
10
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    int a[n+1];
    for(int i = 1 ; i <= n ; i++) cin>>a[i];
    int prefixSum[n+1];
    prefixSum[0] = 0;
    for(int i = 1 ; i <= n ; i++) {
        prefixSum[i] = prefixSum[i-1] + a[i];
    }
    int T; cin>>T;
    while(T--) {
        int u,v; cin>>u>>v;
        cout<<prefixSum[v] - prefixSum[u-1]<<endl;
    }
}