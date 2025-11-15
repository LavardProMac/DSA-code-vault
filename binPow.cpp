const int M=1e9+7;

ll Pow(ll a, ll b, ll r=1){
    while(b){
        if(b&1) r=r*a%M;
        a=a*a%M, b>>=1;
    }return r;
}
ll mul(ll a, ll b){
    if(!b) return 0;
    ll x=mul(a, b>>1)<<1;
    return (x+(b&1)*a)%M;
}
