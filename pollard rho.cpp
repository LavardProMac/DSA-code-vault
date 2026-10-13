#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

using u128=__uint128_t;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ull pr[]={2,3,5,7,11,13,17,19,23,29,31,37};
ull rdm[]={2,325,9375,28178,450775,9780504,1795265022};

inline ull mul(ull a, ull b, ull m){
    return (u128)a*b%m;
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
    if(n<2) return 0;
    for(ull p:pr) if(n%p==0) return n==p;
    ull d=n-1, s=0;
    while(!(d&1)) d>>=1, ++s;
    for(ull a:rdm){
        if(a%n==0) continue;
        ull x=pw(a%n, d, n);
        if(x==1 || x==n-1) continue;
        bool ok=0;
        fo(i,1,s-1){
            x=mul(x, x, n);
            if(x==n-1) {ok=1; break;}
        }
        if(!ok) return 0;
    }
    return 1;
}

inline ull f(ull x, ull c, ull n){
    return (mul(x, x, n)+c)%n;
}

ull rho(ull n){
    for(ull p:pr) if(n%p==0) return p;
    while(true){
        ull y=rd()%(n-2)+2, c=rd()%(n-1)+1;
        ull g=1, r=1, q=1, x=0, ys=0;
        while(g==1){
            x=y; ull k=0;
            fo(i,0,r-1) y=f(y, c, n);
            while(k<r && g==1){
                ys=y; q=1;
                ull lim=min(128ull, r-k);
                fo(i,0,lim-1) y=f(y, c, n),
                    q=mul(q,x>y? x-y:y-x,n);
                g=gcd(q, n); k+=lim;
            }
            r<<=1;
        }
        if(g==n) do ys=f(ys, c, n),
            g=gcd(x>ys? x-ys:ys-x,n);
        while(g==1);
        if(g>1 && g<n) return g;
    }
}
unordered_map<ull, int> mp;

void fac(ull n){
    if(n==1) return;
    if(chk(n)) {++mp[n]; return;}
    ull d=rho(n); fac(d); fac(n/d);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    mp.max_load_factor(0.7);
    mp.reserve(20000);
    while(t--){
        ull n; cin>>n; mp.clear(); fac(n);
        cout<<n<<":\n";
        for(auto [f,s]:mp) cout<<f<<' '<<s<<'\n';
    }
}
