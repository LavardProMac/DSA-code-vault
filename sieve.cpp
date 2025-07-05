#include<bits/stdc++.h>
#define ll long long
#pragma GCC optimize("O3,unroll-loops")
using namespace std; const int N=1e6+1;
bitset<N> p;

inline void sieve(){ p[2]=1;
    for(int i=3; i<N; i+=2) p[i]=1;
    for(int i=3; i<1001; i+=2) if(p[i])
        for(int j=i*i; j<N; j+=i+i) p[j]=0;
}
inline void sang(const int& n){ p[2]=1;
    for(int i=3; i<=n; i+=2) p[i]=1;
    for(int i=3; i*i<=n; i+=2) if(p[i])
        for(int j=i*i; j<=n; j+=i+i) p[j]=0;
}
inline bool isP(const ll& n){
    if(n<2) return 0; if(n<4) return 1;
    if(!(n&1 && n%3)) return false;
    for(int i=5, s=sqrt(n); i<=s; i+=6)
        if(!(n%i && n%(i+2))) return 0;
    return true;
}
