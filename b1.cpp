#include<bits/stdc++.h>
#define ll long long
using namespace std;

inline bool kt(ll a, ll b){
    if(b%a==0) return 1; ll d=b-a;
    for(ll i=1; i*i<=d; ++i) if(d%i==0)
        if(i>=a || d/i>=a) return 1;
    return 0;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; ll a, b; cin>>t;
    while(t--) cin>>a>>b,
        cout<<(kt(a, b)? "YES\n":"NO\n");
}
