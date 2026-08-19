#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
const int M=1e9+7;

void fre(){
    freopen("LNUMBER.INP", "r", stdin); 
    freopen("LNUMBER.OUT", "w", stdout);
}

pair<ll, ll> calc(ll r, ll n){
    if(!n) return {1, 0};
    auto [x, y]=calc(r, n>>1);
    ll X=x*x%M, Y=y*(1+x)%M;
    
    if(n&1) return {X*r%M, (Y+X)%M};
    return {X, Y};
}

void solve(){
    string a; int k; cin>>a>>k;
    ll b=0, p=1;

    for(char c:a){
        if(c=='0' || c=='5') b=(b+p)%M;
        p=(p<<1)%M;
    }
    ll r=p;
    cout<<b*calc(r,k).second%M;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    fre(); solve();
}
