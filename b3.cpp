#include<bits/stdc++.h>
#define ll long long
using namespace std;

inline ll dau(ll a,ll r){
    ll x=a+(r-a%7+7)%7;
    return x;
}
inline ll cuoi(ll b,ll r){
    ll x=b-(b-r+7)%7;
    return x;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; ll a, b, c, s; cin>>t;
    while(t--){ cin>>a>>b; c=s=0;
        for(int i=0; i<7; i+=2){
            ll x=dau(a,i), y=cuoi(b,i);
            if(x>y) continue;
            ll n=(y-x)/7+1;
            c+=n, s+=n*(x+y)/2;
        }cout<<c<<' '<<s<<'\n';
    }
}
