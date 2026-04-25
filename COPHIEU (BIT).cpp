// Câu 4 Phan 2024-2025 (Cổ phiếu)
// Source: c.tmathcoding.vn/contest/9c1200426/task/3

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
const int N=1e5+5; int bit[N];

void upd(int i, const int& v){
    for(; i<N; i+=i&-i) bit[i]=min(bit[i], v);
}

int get(int i, int m=1e9){
    for(; i; i-=i&-i) m=min(m, bit[i]);
    return m;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("COPHIEU.INP", "r", stdin);
    freopen("COPHIEU.OUT", "w", stdout);
    
    int n, x; cin>>n;
    memset(bit, 0x3f, sizeof bit);

    fo(i,1,n) cin>>x,
        cout<<max(0, i-get(x-1))<<' ',
        upd(x, i);
}
