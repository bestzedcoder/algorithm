/*
Description
Compute the sum of two integers a and b.
Input
Line 1 contains two integers a and b (0 <= a, b <= 10^19)
Ouput
Write the sum of a and b
Example
Input
3 5
Output
8
*/

#include<bits/stdc++.h>
using namespace std;
 
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define FOR(i, start, end, k) for (ll i = start; i < end; i += k)
#define REVERSE_FOR(i, end, start, k) for (ll i = end - 1; i >= start; i -= k)
#define SZ(x) (x).size()
#define ll long long
 

void solve()
{
    string u,v;
    cin>>u;
    cin.ignore(1);
    cin>>v;
    string c;
    bool check = true;
    int length;
    if (SZ(u) >= SZ(v))
    {
        length = SZ(v);
        check = false ;
    }
    else
    {
        length = SZ(u);
    }
    vector<int> s;
    s.push_back(0);
    int a = SZ(u)-1,b = SZ(v)-1;
    FOR(i,0,length,1)
    {
        int res = (u[a]-'0') + (v[b]-'0')+s[i];
        if (res >= 10)
        {
            res = res%10;
            c +=(char)(res+'0');
            s.push_back(1);
        }
        else
        {
            c+=(char)(res+'0');
            s.push_back(0);
        }
        a--; b--;
    }
    int ans;
    if (check)
    {
        REVERSE_FOR(i,SZ(u)+SZ(v)-length*2 , 0 ,1)
        {
            ans = v[i] + s.back();
            if (ans >= 10)
          {
            ans = ans%10;
            c +=(char)(ans+'0');
            s.push_back(1);
          }
          else
          {
            c+=(char)(ans+'0');
            s.push_back(0);
          }
        }
    }
    else
    {
        REVERSE_FOR(i,SZ(u)+SZ(v)-length*2 , 0 ,1)
        {
            int ans = u[i] + s.back();
            if (ans >= 10)
          {
            ans = ans%10;
            c +=(char)(ans+'0');
            s.push_back(1);
          }
          else
          {
            c+=(char)(ans+'0');
            s.push_back(0);
          }
        }
    }
    if (s.back()==1)
    {
        c+='1';
        REVERSE_FOR(i,SZ(c),0,1) cout<<c[i];
    }
    else
    {
        REVERSE_FOR(i,SZ(c),0,1) cout<<c[i];
    }

}
int main()
{
 fast_cin();
#ifndef ONLINE_JUDGE
#endif 
     solve();
 }
