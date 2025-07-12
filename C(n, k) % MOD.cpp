using namespace std; const int N=1e6+1;
ll P[N]; const int M=2024;

inline ll mu(ll b, ll e, ll r=1){
    for(; e; e>>=1, b=b*b%m)
        if(e&1) r=r*b%M;
    return r;
}
inline void tsnt(ll x, ll d){
    for(int i=2; i*i<=x; ++i)
        while(x%i==0) x/=i, p[i]+=d;
    if(x>1) p[x]+=d;
}
inline ll nCr(ll n, ll r){
    if(r<0 || r>n) return 0; ll res=1;
    for(int i=n-r+1; i<=n; ++i) tsnt(i,1);
    for(int i=1; i<=r; ++i) tsnt(i,-1);
    for(int i=2; i*i<=N; ++i) if(p[i]) 
        res=res*mu(i,p[i])%M, p[i]=0;
    return res;
}
