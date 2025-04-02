/* Max-Distance Sub-Sequence */
#include<bits/stdc++.h>
using namespace std;


bool invalid(int mid , vector<int>& arr , int k) {
    int count = 1 , lastPosition = arr[0];
    for(int i = 1 ; i < arr.size() ; i++) {
        if(arr[i] - lastPosition >= mid) {
            count++;
            lastPosition = arr[i];
        }
        if(count == k) return true;
    }
    return false;
}

void solution(int k,vector<int> & arr) {
    sort(arr.begin() , arr.end());
    int left = 1 , right = arr[arr.size() - 1] - arr[0];
    int result = 0;
    while(left <= right) {
        int mid = left + (right -left)/2;
        if(invalid(mid,arr , k)) {
            result = mid;
            left = mid + 1;
        } else right = mid - 1;
    }
    cout<< result << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin>>T;
    while(T--) {
        int n,k; cin>>n>>k;
        vector<int> arr(n);
        for(int i = 0 ; i < n ; i++) {
            int u ; cin>>u;
            arr[i] = u;
        }
        solution(k , arr);
    }
}