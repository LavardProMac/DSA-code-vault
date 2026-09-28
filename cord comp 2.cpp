// Source: oj.vnoi.info/problem/c11seq

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=1e5+5;
int n, bit[N]; ll a[N], p[N];

void upd(int i){
    for(; i<=n+1; i+=i&-i) ++bit[i];
}
int get(int i, int c=0){
    for(; i; i-=i&-i) c+=bit[i];
    return c;
}
inline int id(ll x){
    return lower_bound(a, a+n+1, x)-a+1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int L, R, x; cin>>n>>L>>R;
    fo(i,1,n) cin>>x, a[i]=p[i]=p[i-1]+x;
    sort(a, a+n+1); ll ans=0; upd(id(0));

    fo(i,1,n){
        int l=id(p[i]-R);
        int r=upper_bound(a, a+n+1, p[i]-L)-a;
        ans+=get(r)-get(l-1); upd(id(p[i]));
    }
    cout<<ans;
}
