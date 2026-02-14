const int M=1e9+7;

inline ll Pow(ll a, ll b){
    ll res=1;
    while(b){
        if(b&1) res=res*a%M;
        a=a*a%M, b>>=1;
    }
    return res;
}

inline ll Mul(ll a, ll b){
    ll res=0;
    while(b){
        if(b&1) res=(res+a)%M;
        a=(a+a)%M; b>>=1;
    }
    return res;
}
