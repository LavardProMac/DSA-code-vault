#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=1e6, M=2024; //M hợp số
int pr[N], pc=-1;
bitset<N+1> bs; ll e[N+1];

void sieve(){
    fo(i,2,N){
        if(!bs[i]) pr[++pc]=i;
        for(int j=0; j<=pc && i*pr[j]<=N; ++j){
            bs[i*pr[j]]=1;
            if(i%pr[j]==0) break;
        }
    }
}

inline ll Pow(ll a, int b){
    ll res=1;
    for(; b; b>>=1, a=a*a%M)
        if(b&1) res=res*a%M;
    return res;
}

inline int lg(int n, const int& p){
    int cnt=0;
    while(n/=p) cnt+=n;
    return cnt;
}

ll nCk(const int& n, int k){
    if(k<0 || k>n) return 0;
    if(k>n-k) k=n-k; ll res=1;
    
    fo(i,0,pc){
        const int p=pr[i];
        if(p>n) break;
        
        const int v=lg(n, p)-lg(k, p)-lg(n-k, p);
        if(v) res=res*Pow(p, v)%M;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t, n, k; cin>>t; sieve();
    
    while(t--) cin>>n>>k,
        cout<<nCk(n, k)<<'\n';
}
