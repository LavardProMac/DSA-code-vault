#include<bits/stdc++.h>
using namespace std; const int N=1e6+1;
int a[N], c[N];

inline void cntSort(int* a){
    memset(c, 0, sizeof(c));
    int n=a.size(), j=0;
    fo(i,1,n) ++c[a[i]];
    fo(i,1,N) while(c[v]--) a[++j]=v;
}
