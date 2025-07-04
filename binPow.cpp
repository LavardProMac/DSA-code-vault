const int M=1e9+7;

inline ll Pow(ll a, ll b, ll r=1){
    while(b){
        if(b&1) r=r*a%M;
        a=a*a%M, b>>=1;
    }return r;
}
inline ll mul(ll a, ll b){
    if(!b) return 0;
    ll x=mul(a, b>>1);
    return (b&1)? 
        ((x<<1)+a)%M : 2*x%M;
}
