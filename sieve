#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
using namespace std; const int N=1e6+1;
bitset<N> p;

inline void sieve(){ p[2]=1;
    for(int i=3; i<N; i+=2) p[i]=1;
    for(int i=3; i<1001; i+=2) if(p[i])
        for(int j=i*i; j<N; j+=i+i) p[j]=0;
}
