#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define fo(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

const int N=100005;
const ll INF=1e18;

int n,k,a[N];
int ph[N],hd[N],ln[N],pl[1200005];
int ct[N],L=1,R=0;
ll cur;
ll dp[2][N];

void pre(){
    fo(i,0,N-1) ph[i]=i;
    fo(i,2,N-1) if(ph[i]==i)
        for(int j=i;j<N;j+=i) ph[j]-=ph[j]/i;

    vector<int> d[N];
    fo(i,1,N-1)
        for(int j=i;j<N;j+=i)
            d[j].push_back(i);

    int p=0;
    fo(i,1,N-1){
        hd[i]=p;
        ln[i]=d[i].size();
        for(int x:d[i]) pl[p++]=x;
    }
}

inline void add(int i){
    int x=a[i];
    int h=hd[x],l=ln[x];
    fo(j,0,l-1){
        int u=pl[h+j];
        cur+=1LL*ph[u]*ct[u];
        ++ct[u];
    }
}

inline void del(int i){
    int x=a[i];
    int h=hd[x],l=ln[x];
    fo(j,0,l-1){
        int u=pl[h+j];
        --ct[u];
        cur-=1LL*ph[u]*ct[u];
    }
}

void sol(int id,int l,int r,int opl,int opr){
    if(l>r) return;

    int m=(l+r)>>1;
    int op=opl;
    ll res=INF;

    while(R<m) add(++R);
    while(R>m) del(R--);

    while(L>opl+1) add(--L);
    while(L<opl+1) del(L++);

    int lim=min(m-1,opr);

    fo(i,opl,lim){
        if(dp[id^1][i]!=INF&&dp[id^1][i]+cur<res){
            res=dp[id^1][i]+cur;
            op=i;
        }
        if(i<lim) del(L++);
    }

    dp[id][m]=res;

    sol(id,l,m-1,opl,op);
    sol(id,m+1,r,op,opr);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    pre();

    cin>>n>>k;
    fo(i,1,n) cin>>a[i];

    while(R<n){
        add(++R);
        dp[1][R]=cur;
    }
    dp[1][0]=INF;

    fo(i,2,k){
        fo(j,0,n) dp[i&1][j]=INF;
        sol(i&1,i,n,i-1,n-1);
    }

    cout<<dp[k&1][n];
}
