// Source: chuyentinpbc.ucode.vn/problems/10rcitydt-211924

#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define fo(i,l,r) for(int i=l; i<=r; ++i)
using namespace std;

vector<pll> e[100005]; ll d[100005];
map<pll, pll> ban; map<pll, int> len;
priority_queue<pll, vector<pll>, greater<pll>> q;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, a, b, k, g;
    cin>>n>>m>>a>>b>>k>>g;

    int p[g+1], u, v, w; ll cur=-k;
    fo(i,1,g) cin>>p[i];

    fo(i,1,m) cin>>u>>v>>w,
        e[u].emplace_back(v, w),
        e[v].emplace_back(u, w),
        len[{u, v}]=len[{v, u}]=w;
    
    fo(i,1,g-1){
        int u=p[i], v=p[i+1];
        ll w=len[{u, v}];
        ban[{u, v}]=ban[{v, u}]=
            {cur, cur+w}; cur+=w;
    }
    fo(i,1,n) d[i]=4e18;
    q.push({d[a]=0, a});

    while(!q.empty()){
        auto [du, u]=q.top(); q.pop();
        if(du!=d[u]) continue;

        for(auto [v,w]:e[u]){
            ll t=du;
            auto it=ban.find({u,v});
            if(it!=ban.end()){
                ll l=it->second.first;
                ll r=it->second.second;
                if(l<=t && t<r) t=r;
            }
            if(d[v]>t+w) d[v]=t+w,
                q.push({d[v], v});
        }
    }
    cout<<d[b];
}
