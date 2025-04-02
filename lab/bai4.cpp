//C++ 
#include <bits/stdc++.h> 
using namespace std;
int main() 
{ 
    int n; cin>>n;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++) cin>>arr[i];
    sort(arr.begin() , arr.end() , greater<int>());
    int currentTime  , result = 0;
    for(int  i = 0 ; i < n ; i++) {
        // cout<<arr[i] << " "<<result <<endl ;
        currentTime = i + arr[i];

        if(result < currentTime) result = currentTime ;
    }
    cout<<result;
    return 0;
}
