/*
Description
Cho dãy a1, a2, ..., an trong đó các phần tử đôi một khác nhau và 1 giá trị nguyên dương M.
Hãy đếm số Q các cặp (i,j) sao cho 1 <= i < j <= n và ai + aj = M.

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
    int a[n]; for(int i = 0 ; i < n; i++) cin>>a[i];
    int count = 0 ;
    sort(a, a+n);
    for(int i = 0 ; i < n ; i++) {
        int l = i + 1 , r = n - 1;
        while(l<=r) {
            int mid = l + ( r - l )/2;
            int ans = a[mid] + a[i];
            if(ans == M) {
                count++;
                break;
            } else if(ans < M) l = mid + 1;
            else if(ans > M) r = mid - 1;
        }
    }
    cout<<count;
    return 0;
}