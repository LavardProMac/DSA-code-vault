https://oj.cppro.vn/contests/prevoi2026_w01/problem/caytao2

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
const int N=1e5+5;

int n, a[N], b[N], bit[N];
int l[N], r[N], k[N], L[N], R[N];
vector<int> p[N], bk[N];

void upd(int x){
    for(; x<=n; x+=x&-x) ++bit[x];
}

int get(int x, int c=0){
    for(; x; x-=x&-x) c+=bit[x];
    return c;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int q; cin>>n>>q;
    fo(i,1,n) cin>>a[i], b[i]=a[i];
    
    sort(b+1, b+n+1);
    int m=unique(b+1, b+n+1)-b-1;
    
    fo(i,1,n)
        a[i]=lower_bound(b+1, b+m+1, a[i])-b,
        p[a[i]].push_back(i);
    
    fo(i,1,q) L[i]=1, R[i]=m,
        cin>>l[i]>>r[i]>>k[i];
    
    while(true){
        bool ok=1; int cnt;
        fo(i,1,m) bk[i].clear();
        memset(bit, 0, sizeof bit);
        
        fo(i,1,q) if(L[i]<R[i]) ok=0,
            bk[L[i]+R[i]>>1].push_back(i);
        if(ok) break;
        
        fo(x,1,m){
            for(int i:p[x]) upd(i);
            for(int i:bk[x])
                cnt=get(r[i])-get(l[i]-1),
                cnt>=k[i]? R[i]=x:L[i]=x+1;
        }
    }
    fo(i,1,q) cout<<b[L[i]]<<'\n';
}
