#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++) cin>>arr[i];
    long long current_prefix = 0;
    long long min_even = 0;
    long long min_odd = LLONG_MAX;
    long long max_prefix = LLONG_MIN;

    for(int i = 0 ; i < n ; i++) {
        current_prefix += arr[i];

        if(current_prefix % 2 == 0) {
            long long prefix = current_prefix - min_even;
            if(prefix > max_prefix) {
                max_prefix =  prefix;
            }
            if(current_prefix < min_even) min_even = current_prefix;
        } else {
            if(min_odd != LLONG_MAX) {
                long long prefix = current_prefix - min_odd;
                if(prefix > max_prefix) max_prefix = prefix;
            }
            if(current_prefix < min_odd) min_odd = current_prefix;
        }
    }

    if(max_prefix ==  LLONG_MIN) cout<<"NOT_FOUND!"<<"\n";
    else  cout<<max_prefix;
}