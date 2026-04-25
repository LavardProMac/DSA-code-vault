inline ll mul(ll a, ll b, ll m){
    return (__int128)a*b%m;
}

ll pw(ll a, ll d, ll m){
    ll r=1;
    for(; d; d>>=1, a=mul(a, a, m))
        if(d&1) r=mul(r, a, m);
    return r;
}

bool isP(ll n){
    if(n<2) return 0;
    
    for(int p:{2,3,5,7,11,13,17,19,23,29})
        if(n%p==0) return n==p;

    ll d=n-1, s=0;
    while(!(d&1)) d>>=1, ++s;

    for(int a:{2,325,9375,28178,450775,9780504,1795265022}){
        if(a%n==0) continue;
        ll x=pw(a, d, n);
        
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
