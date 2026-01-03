#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, l, r; cin>>n>>l>>r;
    ll a[n+1], p[n+1]; p[0]=0;
    fo(i,1,n) cin>>a[i], p[i]=p[i-1]+a[i];
    deque<ll> dq; ll ans=-1e18;
    fo(i,l,n){
        int j=i-l;
        while(!dq.empty() && p[dq.back()]>=p[j])
            dq.pop_back();
        dq.push_back(j);
        while(!dq.empty() && dq.front()<i-r)
            dq.pop_front();
        ans=max(ans, p[i]-p[dq.front()]);
    }
    cout<<ans;
}
