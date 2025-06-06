/*
Bài toán: Sum pair of sequence equal to a number

Description
Cho dãy a1, a2, ..., an trong đó các phần tử đôi một khác nhau và 1 giá trị nguyên dương M. Hãy đếm số Q các cặp (i,j) sao cho 1 <= i < j <= n và ai + aj = M.

Dữ liệu
Dòng 1: ghi n và M (1 <= n, M <= 1000000)
Dòng 2: ghi a1, a2, ..., an
Kết quả
Ghi ra giá trị Q
Ví dụ
Dữ liệu
5 6
5 2 1 4 3
Kết quả
2
*/

#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,M; cin>>n>>M;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin>>a[i];
    sort(a.begin() , a.end());

    int result = 0;
    for(int i = 0 ; i < n ; i++) {
        int l = i+1 ,  r = n - 1;
        while(l<=r) {
            int mid = l + (r - l)/2;
            if(a[mid] + a[i] == M)
            {
                result++;
                l = mid + 1;
                continue;
            }
            if(a[mid] + a[i] < M) l = mid + 1;
            if(a[mid] + a[i] > M) r = mid - 1;
        }
    }
    cout<<result;
    return 0;
}