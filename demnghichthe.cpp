#include<bits/stdc++.h>
#define ll long long
//#define pii pair<int, int>
//#pragma GCC target("avx2,bmi2")
//#pragma GCC optimize("O3,unroll-loops")
#define fo(i,j,n) for(int i=j; i<n; ++i)
using namespace std;

inline ll tri(vector<int> &a, vector<int> &kq, int l, int m, int r){
    ll dem=0; int i=l, j=m+1, k=l;   
    while(i<=m && j<=r)
        if(a[i]<=a[j]) kq[k++]=a[i++];
        else kq[k++]=a[j++], dem+=m-i+1;
    while(i<=m) kq[k++]=a[i++];
    while(j<=r) kq[k++]=a[j++];
    for(int i=l; i<=r; ++i) a[i]=kq[i];
    return dem;
}
inline ll chia(vector<int> &a, vector<int> &kq, int l, int r){
    if(l>=r) return 0; int m=l+r>>1;
    return chia(a, kq, l, m)+chia(a, kq, m+1, r)+tri(a, kq, l, m, r);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<int> kq(n), a(n);
    for(int &x:a) cin>>x;
    cout<<chia(a, kq, 0, n-1);
}
