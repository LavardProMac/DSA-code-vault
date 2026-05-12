#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin>>n>>k;
    deque<int> dq;
    
    ll p[n+1], ans=-1e18; p[0]=0;
    fo(i,1,n) cin>>p[i], p[i]+=p[i-1];
    
    fo(i,1,n){
        while(!dq.empty() && p[dq.back()]>=p[i])
            dq.pop_back();
        dq.push_back(i-1);
        
        if(dq.front()<i-k) dq.pop_front();
        ans=max(ans, p[i]-p[dq.front()]);
    }
    cout<<ans;
}
