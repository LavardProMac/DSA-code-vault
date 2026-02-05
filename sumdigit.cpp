inline int sdg(ll n){
    int cnt=n%10;
    while(n/=10) cnt+=n%10;
    return cnt;
}
