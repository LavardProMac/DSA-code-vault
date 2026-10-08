https://oj.cppro.vn/contests/prevoi2026_w01/problem/caytao2

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
const int N=1e5+5;

int l[N], r[N], L[N], R[N];
ll a[N], w[N], bit[N];
vector<int> bk[N];

void upd(int x, ll v){
    for(; x<=N; x+=x&-x) bit[x]+=v;
}

ll get(int x, ll s=0){
    for(; x; x-=x&-x) s+=bit[x];
    return s;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n>>q;
    fo(i,1,n) cin>>a[i], L[i]=1, R[i]=q+1;
    fo(i,1,q) cin>>l[i]>>r[i]>>w[i];
    
    while(true){
        bool ok=1;
        fo(i,1,q+1) bk[i].clear();
        memset(bit, 0, sizeof bit);
        
        fo(i,1,n) if(L[i]<R[i]) ok=0,
            bk[L[i]+R[i]>>1].push_back(i);
        if(ok) break;
        
        fo(i,1,q){
            upd(l[i], w[i]); upd(r[i]+1, -w[i]);
            for(int j:bk[i])
                get(j)>=a[j]? R[j]=i:L[j]=i+1;
        }
    }
    fo(i,1,n) cout<<(L[i]<=q? L[i]:-1)<<' ';
}
