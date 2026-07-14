// Source: thna2026.contest.codeforces.com/group/6RNNwQPrCL/contest/703925/problem/G

#include<bits/stdc++.h>
#define ll long long
#define fo(i,l,r) for(int i=l; i<=r; ++i)
#define fd(i,r,l) for(int i=r; i>=l; --i)
#pragma GCC target("avx2,bmi2")
#pragma GCC optimize("Ofast,unroll-loops")
using namespace std;

const int N=5005;
bitset<N> dp[N], m;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, x, y; cin>>n>>x>>y;
    int ans=0; dp[0][0]=1;

    fo(i,1,n){
        int a, b, c, d;
        cin>>a>>b>>c>>d;

        int lp=max(0, a-x);
        int rp=min(i-1, b-x);
        int lt=max(0, c-y);
        int rt=min(i-1, d-y);
        
        if(lp>rp || lt>rt) continue;
        m.reset();
        fo(j,lt,rt) m.set(j);

        fd(p,rp,lp){
            bitset<N> t=dp[p]&m;
            if(!t.any()) continue;
            dp[p+1]|=t; dp[p]|=t<<1;
        }
    }
    fo(p,0,n) fd(t,n,0) if(dp[p][t]){
        ans=max(ans, p+t); break;
    }
    cout<<ans;
}
