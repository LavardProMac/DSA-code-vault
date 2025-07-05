inline int binPow(int a, int k, const ll& n){ int r=1;
    for(a%=n; k; k>>=1, a=(1LL*a*a)%n) if(k&1) r=(1LL*r*a)%n;
    return r;
}
inline bool test(const int& a, const ll& n, const int& k, const int& m){
    int x=binPow(a,m,n); if(x==1 || x==n-1) return true;
    for(int i=1; i<k; ++i) if((x=1LL*x*x%n)==n-1) return true;
    return false;
}
inline bool isP(const ll& n){
    if(n<2) return false; if(n<4) return true;
    if(!(n&1 && n%3)) return false;
    int k=0, m=n-1; while(!(m&1)) m>>=1, ++k;
    if(!test(2,n,k,m)) return false;
    if(!test(3,n,k,m)) return false;
    return true;
}
