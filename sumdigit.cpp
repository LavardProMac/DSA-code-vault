inline int sdg(ll n, int d=0){
    while(n) d+=n%10, n/=10;
    return d;
}
