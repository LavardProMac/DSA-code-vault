#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=1e6+1;
int n, lg[N], a[N], st[20][N];

void build(){
    st[0][1]=a[1];
    fo(i,2,n) lg[i]=lg[i>>1]+1, st[0][i]=a[i];

    for(int k=1, t=2; t<=n; ++k, t<<=1) fo(i,1,n-t+1)
        st[k][i]=st[k-1][i]+st[k-1][i+(t>>1)];
}

inline int qry(int l, int r){
    const int j=lg[r-l+1];
    return st[j][l]+st[j][r-(1<<j)+1]);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int q, l, r; cin>>n>>q;
    
    fo(i,1,n) cin>>a[i];
    build();
    
    while(q--) cin>>l>>r,
        cout<<qry(l, r)<<'\n';
}
