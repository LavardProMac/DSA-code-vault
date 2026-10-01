// https://fptoj.com/problem/wt-kth-smallest

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
const int N=1e5+5, LOG=16;

int n, m, a[N], b[N], t[N];
int p[LOG+1][N], z[LOG+1];

void build(){
    fo(k,0,LOG){
        int m=LOG-k, cnt=p[k][0]=0;
        fo(i,1,n){
            p[k][i]=p[k][i-1]+!(a[i]>>m&1);
            if(!(a[i]>>m&1)) t[++cnt]=a[i];
        }
        z[k]=cnt;
        fo(i,1,n) if(a[i]>>m&1) t[++cnt]=a[i];
        fo(i,1,n) a[i]=t[i];
    }
}

inline int kth(int l, int r, int k){
    int ans=0;
    fo(i,0,LOG){
        int m=LOG-i, cl=p[i][l-1];
        int cr=p[i][r], cnt=cr-cl;
        
        if(k<=cnt) l=cl+1, r=cr;
        else l=z[i]+l-cl, r=z[i]+r-cr,
            ans|=1<<m, k-=cnt;
    }
    return b[ans];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int q; cin>>n>>q;
    fo(i,1,n) cin>>a[i], b[i]=a[i];
    
    sort(b+1, b+n+1);
    fo(i,1,n) a[i]=lower_bound(b+1, b+n+1, a[i])-b;
    
    build(); int l, r, k;
    while(q--) cin>>l>>r>>k, cout<<kth(l, r, k)<<'\n';
}
