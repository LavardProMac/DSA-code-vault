#include<bits/stdc++.h>
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std; const int N=1e6+1;
int n, a[N], c[N+1];

inline void cntSort(){
    memset(c, 0, sizeof(c));
    fo(i,1,n) ++c[a[i]]; int j=0;
    fo(i,1,N) while(c[v]--) a[++j]=v;
}
