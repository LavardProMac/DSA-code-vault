// Source: thna2026.contest.codeforces.com/group/6RNNwQPrCL/contest/703925/problem/E

#include<bits/stdc++.h>
#define ll long long
#define fo(i,l,r) for(int i=l; i<=r; ++i)
#pragma GCC target("avx2,bmi2")
#pragma GCC optimize("O3,unroll-loops")
using namespace std;
const ll INF=2e18;

struct seg{
    int n;
    vector<ll> st, lz;

    seg(int _n){
        n=_n;
        st.assign(4*n+5, 0);
        lz.assign(4*n+5, 0);
    }
    void bld(int id, int l, int r, vector<ll> &a){
        if(l==r) {st[id]=a[l]; return;}
        int m=l+r>>1, k=id<<1;
        bld(k, l, m, a); bld(k|1, m+1, r, a);
        st[id]=min(st[k], st[k|1]);
    }
    void pd(int id){
        if(!lz[id]) return;
        int k=id<<1;
        st[k]+=lz[id]; st[k|1]+=lz[id];
        lz[k]+=lz[id]; lz[k|1]+=lz[id];
        lz[id]=0;
    }
    void upd(int id, int l, int r, int u, int v, ll x){
        if(v<l || r<u) return;
        if(u<=l && r<=v){
            st[id]+=x; lz[id]+=x; return;
        }
        int m=l+r>>1, k=id<<1; pd(id);
        upd(k,l,m,u,v,x);
        upd(k|1,m+1,r,u,v,x);
        st[id]=min(st[k], st[k|1]);
    }
    ll get(int id, int l, int r, int u, int v){
        if(v<l||r<u) return INF;
        if(u<=l&&r<=v) return st[id];
        
        int m=l+r>>1, k=id<<1; pd(id);
        return min(get(k,l,m,u,v),
                   get(k|1,m+1,r,u,v));
    }
};

struct qry{
    ll d; int l, r, id;
    bool operator<(const qry &o)const{
        if(d!=o.d) return d<o.d;
        if(r-l!=o.r-o.l) return r-l<o.r-o.l;
        return id>o.id;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; ll x; cin>>n>>x;
    vector<ll>d(n+1), f(n+1), g(n+1);

    fo(i,1,n) cin>>d[i];
    fo(i,1,n) cin>>f[i];

    fo(i,1,n)
        if(i<=n/2) g[i]=max(f[i], f[n-i+1]);
        else g[i]=min(f[i], f[n-i+1]);
    ll cur=x; int ans=0;

    fo(i,1,n){
        cur-=d[i];
        if(cur<0) break;
        ans=i; cur+=g[i];
    }
    if(!ans) return cout<<"0 0", 0;
    vector<ll> s(ans+1); cur=x;
    
    fo(i,1,ans)
        cur-=d[i], s[i]=cur, cur+=g[i];
    vector<qry>q;

    fo(i,1,n/2){
        if(f[n-i+1]>f[i]){
            int l=i+1, r=min(ans, n-i+1);
            if(l<=r) q.push_back({f[n-i+1]-f[i],l,r,i});
        }
    }
    sort(q.begin(), q.end());
    seg st(ans);
    st.bld(1, 1, ans, s);
    int cnt=0;

    for(auto &x:q)
        if(st.get(1,1,ans,x.l,x.r)>=x.d)
            st.upd(1,1,ans,x.l,x.r,-x.d),
            ++cnt;
    cout<<ans<<' '<<(int)q.size()-cnt;
}
