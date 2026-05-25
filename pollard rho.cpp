#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

inline ull mul(ull a, ull b, ull m){
    return __int128(a)*b%m;
}

ull pw(ull a, ull b, ull m){
    ull r=1;
    while(b){
        if(b&1) r=mul(r,a,m);
        a=mul(a,a,m); b>>=1;
    }
    return r;
}

bool chk(ull n){
    if(n<2||n%2==0) return n==2;

    ull d=n-1,s=0;
    while(!(d&1)) d>>=1, ++s;

    for(ull a:{2,325,9375,28178,450775,9780504,1795265022}){

        if(a%n==0) continue;
        ull x=pw(a,d,n);

        if(x==1||x==n-1) continue;
        bool ok=0;

        fo(i,1,s-1){
            x=mul(x,x,n);
            if(x==n-1) {ok=1; break;}
        }
        if(!ok) return 0;
    }
    return 1;
}

ull rho(ull n){
    if(n%2==0) return 2;

    ull c=uniform_int_distribution<ull>
    (1,n-1)(rd), d=1;

    ull x=uniform_int_distribution<ull>
    (0,n-1)(rd), y=x;

    auto f=[&](ull x){
        return (mul(x,x,n)+c)%n;
    };
    while(d==1){
        x=f(x); y=f(f(y));
        d=gcd<ull>(abs((ll)x-(ll)y),n);
    }
    return d==n? rho(n):d;
}
unordered_map<ll, int> mp;

inline void fac(const ull& n){
    if(n==1) return;
    if(chk(n)) {++mp[n]; return;}
    ull d=rho(n); fac(d); fac(n/d);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; ull n; cin>>t;
    mp.max_load_factor(0.5);

    while(t--){
        cin>>n; mp.clear(); fac(n);
        for(auto [f,s]:mp) cout<<f<<' '<<s<<'\n';
    }
}
