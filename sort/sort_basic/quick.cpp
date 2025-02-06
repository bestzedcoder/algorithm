/*
quick sort
*/
#include<bits/stdc++.h>
using namespace std;

void quickSort(vector<int>& v , int left , int right) {
    int mid = left + ( right - left ) / 2;
    int p = v[mid];
    int l = left, r = right;
    // sort all trong [r , l] nhỏ hơn p nằm bên trái p lớn hơn nằm bên phải p
    while(l < r) {
        while( v[l] < p) l++;
        while (v[r] > p) r--;
        if(l<=r) {
            int temp = v[l];
            v[l] = v[r];
            v[r] = temp;
            l++;
            r--;
        }
    }
    // nếu l còn nhỏ hơn right nghĩa là p k nằm ở ngoài cùng bên phải 
    if (l < right){
		quickSort(v, l, right);
	}
    //nếu r còn lớn hơn left nghĩa là p k nằm ở ngoài cùng bên trái 
	if (left < r){
		quickSort(v, left, r);
	}
}

int main() {
    int n; cin>>n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin>>v[i];
    quickSort(v , 0 , n - 1);
    for(int x : v) cout<<x<<'/n';
    return 0;
}