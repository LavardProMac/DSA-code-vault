#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
const int N=1e6+5, LOG=20;
ll a[N], st[LOG][N];
int lg[N], n, q;

void tienxuly(){
    lg[1]=0;
    fo(i,2,n) lg[i]=lg[i/2]+1;
    fo(i,1,n) st[0][i]=a[i];
    for(int k=1; (1<<k)<=n; ++k)
        fo(i,1,n-(1<<k)+1)
            st[k][i]=min(st[k-1][i], 
            st[k-1][i+(1<<(k-1))]);
}
inline ll qry(int l, int r){
    int j=lg[r-l+1];
    return min(st[j][l],
           st[j][r-(1<<j)+1]);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>q;
    fo(i,1,n) cin>>a[i];
    tienxuly(); int l, r;
    while(q--) cin>>l>>r,
        cout<<qry(l, r)<<'\n';
}
