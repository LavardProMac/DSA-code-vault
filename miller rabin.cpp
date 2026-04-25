ll Pow(ll a, int k, ll M){
    ll res=1; a%=M;
    for(; k; k>>=1, a=a*a%M)
        if(k&1) res=res*a%M;
    return res;
}

bool kt(int a, ll n, int k, int m){
    ll x=Pow(a, m, n--);
    if(x==1 || x==n) return 0;
    
    fo(i,0,k) if((x=x*x%n)==n) return 1;
    return 0;
}

bool isP(ll n){
    if(n<2) return 0; if(n<4) return 1;
    if(!(n&1 && n%3)) return 0;
    
    int k=0, m=n-1;
    while(!(m&1)) m>>=1, ++k;
    
    if(kt(2,n,k,m)||kt(3,n,k,m)) return 0;
    return 1;
}
