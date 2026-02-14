// Câu 4 Phan 2024-2025 (Cổ phiếu)
// Link đề: www.chuyentin.pro/2024/06/e-thi-tuyen-sinh-lop-10-chuyen-tin_13.html

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=5e6+1; int m;
ll a[N], b[N], bit[N];

inline void upd(int i, const ll& v){
    for(; i<=m; i+=i&-i)  Min(bit[i], v);
}

inline ll get(int i, ll ans=1e18){
    for(; i; i-=i&-i) Min(ans, bit[i]);
    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("COPHIEU.INP", "r", stdin);
    freopen("COPHIEU.OUT", "w", stdout);
    
    cin>>n; set<ll> s;
    fo(i,1,n) cin>>a[i], s.insert(a[i]);
    
    for(const ll& v:s) b[++m]=v;
    fo(i,0,m) bit[i]=1e18;
    
    fo(i,1,n){
        int p=lower_bound(b+1, b+m+1, a[i])-b;
        ll q=p>1? get(p-1):i;
        cout<<i-q<<' '; upd(p, i);
    }
}
