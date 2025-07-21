#include<bits/stdc++.h>
#define ll long long
#pragma GCC target("avx2,bmi2")
#pragma GCC optimize("O3,unroll-loops")
#define fo(i,j,n) for(int i=j;i<=n;++i)
using namespace std; const int N=1e6+5;
int a[N], kq[N];

inline ll tri(int l, int m, int r){
    ll d=0; int i=l, j=m+1, k=l;
    while(i<=m && j<=r)
        if(a[i]<=a[j]) kq[k++]=a[i++];
        else kq[k++]=a[j++], d+=m-i+1;
    while(i<=m) kq[k++]=a[i++];
    while(j<=r) kq[k++]=a[j++];
    fo(i,l,r) a[i]=kq[i];
    return d;
}
inline ll chia(int l, int r){
    if(l>=r) return 0; int m=l+r>>1;
    return chia(l,m)+chia(m+1,r)+tri(l,m,r);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n; fo(i,0,n) cin>>a[i];
    cout<<chia(0, n-1);
}
