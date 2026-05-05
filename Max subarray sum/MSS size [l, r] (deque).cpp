#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, l, r; cin>>n>>l>>r;
    deque<int> dq;

    ll p[n+1], ans=-1e18; p[0]=0;
    fo(i,1,n) cin>>p[i], p[i]+=p[i-1];
    
    fo(i,l,n){
        while(!dq.empty() && p[dq.back()]>=p[i-l])
            dq.pop_back();
        dq.push_back(i-l);
        
        if(!dq.empty() && dq.front()<i-r)
            dq.pop_front();
        ans=max(ans, p[i]-p[dq.front()]);
    }
    cout<<ans;
}
