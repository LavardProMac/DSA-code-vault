// Source: vjudge.net/contest/845930#problem/D

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

struct st{
    ll v; int l, c;
    bool operator<(const st& x) const{
        return v<x.v;
    }
};

void solve(){
    int n; cin>>n;
    vector<int> v; int a[n+1];
    fo(i,1,n) cin>>a[i];

    fo(i,2,n){
        int d=a[i]-a[i-1];
        if(!d){
            if(v.empty() || v.back())
                v.push_back(0);
        }else v.push_back(d);
    }
    int m=v.size();
    if(!m) {cout<<"2\n"; return;}

    vector<st> f[m]; int dp[m];
    memset(dp, 0x3f, sizeof dp);

    fo(i,0,m-1){
        f[i].push_back({v[i], i, i? dp[i-1]+1:1});
        for(int p=0; p<f[i].size(); ++p){
            st x=f[i][p];
            if(!x.l || !x.v) continue;

            int j=x.l-1; st t={x.v, 0, 0};
            auto it=lower_bound(f[j].begin(), f[j].end(), t);
            if(it==f[j].end() || it->v!=x.v) continue;

            int l=it->l, c=l? dp[l-1]+1:1;
            f[i].push_back({x.v*2, l, c});
        }
        sort(f[i].begin(), f[i].end());
        for(auto x:f[i]) dp[i]=min(dp[i], x.c);
    }
    cout<<dp[m-1]+1<<'\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
}
