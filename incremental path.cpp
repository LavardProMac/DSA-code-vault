#include<bits/stdc++.h>
#define fo(i,j,n) for(int i=j; i<n; ++i)
using namespace std; using ll=long long;
unordered_map<ll, ll> p; set<ll> S;

inline ll find(const ll& x){
    auto it=p.find(x);
    if(it==p.end()) return x;
    if(it->second==x) return x;
    return it->second=find(it->second);
}
inline void mark(const ll& x){
    if(find(x)!=x) return;
    ll nx=find(x+1);
    p[x]=nx; S.insert(x);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t, n, m; cin>>t;
    ll a[100005]; string s;
    while(t--){ cin>>n>>m>>s;
        p.clear(); S.clear(); ++n;
        fo(i,0,m) cin>>a[i], mark(a[i]);
        fo(i,1,n){ ll pos=1;
            fo(j,0,i)
                pos=(s[j]=='A'? 
                pos+1 : find(pos+1));
            mark(pos);
        }cout<<S.size()<<'\n';
        for(ll x:S) cout<<x<<' ';
        cout<<'\n';
    }
}
