// Source: cses.fi/problemset/task/1650

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n>>q;
    
    int x, p[n+1], l, r;
    fo(i,1,n) cin>>x, p[i]=p[i-1]^x;
    
    while(q--) cin>>l>>r,
        cout<<(p[r]^p[l-1])<<'\n';
}
