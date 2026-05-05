#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, l, r, x; cin>>n>>l>>r;
    multiset<ll> ms;
    
    ll p[n+1], ans=-1e18; p[0]=0;
    fo(i,1,n) cin>>x, p[i]=p[i-1]+x;
        
    fo(i,l,n){
        ms.insert(p[i-l]);
        if(i>r) ms.erase(ms.find(p[i-r-1]));
        ans=max(ans, p[i]-*ms.begin());
    }
    cout<<ans;
}
