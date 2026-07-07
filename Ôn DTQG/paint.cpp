// Source: gspvh2627.contest.codeforces.com/group/GXYpZfKThs/contest/702381/problem/A

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("paint.inp", "r", stdin);
    freopen("paint.out", "w", stdout);
    
    ll a, b, c, d; cin>>a>>b>>c>>d;
    if(a>b) swap(a, b);
    if(c>d) swap(c, d);
    
    ll giao=max(0ll, min(d, b)-max(a, c));
    cout<<d+b-a-c-giao;
}
