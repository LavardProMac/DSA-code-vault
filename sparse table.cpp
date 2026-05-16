// Name: Range mininum queries
// Source: cses.fi/problemset/task/1647

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j, m=n; i<=m; ++i)
using namespace std;

const int N=2e5+1;
int n, lg[N], a[N], st[18][N];

void build(){
    st[0][1]=a[1];
    fo(i,2,n) lg[i]=lg[i>>1]+1, st[0][i]=a[i];

    fo(i,1,log2(n)) fo(j,1,n-(1<<i)+1)
        st[i][j]=min(st[i-1][j], st[i-1][j+(1<<i-1)]);
}

inline int qry(int l, int r){
    const int j=lg[r-l+1];
    return min(st[j][l], st[j][r-(1<<j)+1]);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int q, l, r; cin>>n>>q;
    
    fo(i,1,n) cin>>a[i];
    build();
    
    while(q--) cin>>l>>r,
        cout<<qry(l, r)<<'\n';
}
