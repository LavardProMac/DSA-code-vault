#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=1e5;
bitset<N+1> a; int p[N+1][100];

void sieve(){
    fo(i,2,316) if(!a[i])
        for(int j=i*i; j<=N; j+=i) a[j]=1;
}

void prep(){
    fo(i,2,N){
        memcpy(p[i], p[i-1], sizeof p[i]);
        if(!a[i]) ++p[i][i%100*i%100];
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("NUMBER.INP", "r", stdin);
    freopen("NUMBER.OUT", "w", stdout);

    sieve(); prep();
    int t, k; ll l, r; cin>>t;

    while(t--){
        cin>>l>>r>>k;
        int a=sqrt(l-1), b=sqrt(r);
        cout<<p[b][k]-p[a][k]<<'\n';
    }
}
