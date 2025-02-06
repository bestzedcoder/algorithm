/*
merge sort
*/

#include<bits/stdc++.h>
using namespace std;


// phân hoạch đoạn
void merge(vector<int>& v , int left , int mid , int right) {
    int i = left , j = mid + 1;
    int k = 0;
    vector<int> temp(right - left + 1);
    while( i <= mid && j <= right ) {
        if(v[i] <= v[j]) temp[k++] = v[i++];
        else temp[k++] = v[j++];
    }
    while(i <= mid) temp[k++] = v[i++];
    while(j <= right) temp[k++] = v[j++];
    for(int i = 0 ; i < right - left + 1 ; i++) {
        v[left + i] = temp[i];
    }
}


// merge 2 đoạn [left, mid] và [mid + 1 , right]
void mergeSort(vector<int>& v , int left , int right) {
    if(left >= right) return;
    int mid = left + (right - left)/2;
    mergeSort(v , left , mid);
    mergeSort(v,mid+1,right);
    merge(v,left,mid,right);
}

int main() {
    int n; cin>>n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin>>v[i];
    mergeSort(v , 0 , n - 1);
    for(int x : v) cout<<x<<"\n";
}