const int N=1e6, M=2024;
ll p[N+1];

ll Pow(ll a, ll b){
    ll res=1;
    for(; b; b>>=1, a=a*a%M)
        if(b&1) res=res*a%M;
    return res;
}

void tsnt(ll x, const int& d){
    while(!(x&1)) x>>=1, p[2]+=d;
    for(int i=3; i*i<=x; i+=2)
        while(x%i==0) x/=i, p[i]+=d;
    if(x>1) p[x]+=d;
}

ll nCr(const int& n, const int& r){
    if(r<0 || r>n) return 0;
    ll res=1;
    fo(i,n-r+1,n) tsnt(i, 1);
    fo(i,1,r) tsnt(i, -1);
    fo(i,2,1000) if(p[i]) 
        res=res*Pow(i, p[i])%M, p[i]=0;
    return res;
}
