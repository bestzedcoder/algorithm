#include<bits/stdc++.h>
using namespace std;

bool is_valid(int mid , vector<int>& arr , int k) {
    int count = 1;
    int current = arr[0];
    for(int x : arr) {
        if(x - current >= mid) {
            count++;
            current = x;
        }
        if(count == k) return true;
    }
    return false;
}

void solution(vector<int>& arr,int k) {
    sort(arr.begin() , arr.end());
    int left = 1, right = arr[arr.size() - 1] - arr[0];
    int result = 0;
    while( left <= right) {
        int mid = left + (right - left)/2;
        if(is_valid(mid , arr , k)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T-- > 0) {
        int n, k ; cin>>n>>k;
        vector<int> arr(n);
        for(int i = 0 ; i < n ; i++) cin>>arr[i];
        solution(arr,k);
    }
}