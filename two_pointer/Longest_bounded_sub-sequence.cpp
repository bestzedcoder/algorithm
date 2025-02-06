/*
Bài toán: Longest bounded sub-sequence

Mô tả:
Cho một dãy số nguyên dương (a = a_1, a_2, \ldots, a_n). Một dãy con của (a) được định nghĩa là một dãy các phần tử liên tiếp (a_i, a_{i+1}, \ldots, a_j) (1 <= i <= j <= n). Trọng lượng của một dãy con là tổng các phần tử của nó. Cho một số nguyên dương (Q). Một dãy con được gọi là khả thi nếu trọng lượng của nó nhỏ hơn hoặc bằng (Q).
Hãy tìm một dãy con khả thi sao cho số lượng phần tử của dãy con đó là lớn nhất.

Đầu vào:

Dòng 1: chứa hai số nguyên dương (n) và (Q) (1 <= (n) <= 10^6, 1 <= (Q) <= 100000)
Dòng 2: chứa các số (a_1, a_2, \ldots, a_n) (1 <= (a_i) <= 10000).
Đầu ra:

In ra số lượng phần tử của dãy con tìm được, hoặc in ra -1 nếu không tồn tại dãy con như vậy.
Ví dụ:

Đầu vào:
6 20
2 2 5 6 5 7

Đầu ra:
5
*/

#include<bits/stdc++.h>
using namespace std;
int main() {
    int n , M; cin>>n>>M;
    int a[n];
    for(int i = 0 ; i < n ; i++) {
        cin>>a[i];
    }
    int prefixSum[n+1];
    prefixSum[0] = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        prefixSum[i] = prefixSum[i-1] + a[i-1];
    }
    int result = 0 , index = 1;
    for(int i = 1 ; i <= n ; i++) {
        if(prefixSum[i] - prefixSum[index-1] <= M) {
            result = max(result , i - index + 1);
            continue;
        }
        index++;
    }
    cout<<result;
    return 0;

}