// https://fptoj.com/problem/wt-range-count-in

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

inline int get(int l, int r, int x){
    if(x<=0) return 0;
    if(x>m) return r-l+1;
    int ans=0;
    fo(i,0,LOG){
        int m=LOG-i, cl=p[i][l-1];
        int cr=p[i][r], cnt=cr-cl;
        
        if(x>>m&1) ans+=cnt,
            l=z[i]+l-cl, r=z[i]+r-cr;
        else l=cl+1, r=cr;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int q; cin>>n>>q;
    fo(i,1,n) cin>>a[i], b[i]=a[i];
    
    sort(b+1, b+n+1);
    m=unique(b+1, b+n+1)-b-1;
    fo(i,1,n) a[i]=lower_bound(b+1, b+m+1, a[i])-b;
    build();
    
    while(q--){
        int l, r, x, y; cin>>l>>r>>x>>y;
        int u=lower_bound(b+1, b+m+1, x)-b;
        int v=upper_bound(b+1, b+m+1, y)-b;
        cout<<get(l, r, v)-get(l, r, u)<<'\n';
    }
}
