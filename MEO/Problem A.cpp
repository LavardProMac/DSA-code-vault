// Name: Bộ ba thú vị

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("TRIAD.INP", "r", stdin);
    freopen("TRIAD.OUT", "w", stdout);
  
    int a, b, c; cin>>a>>b>>c;
    int N=2e6, ans=2e9, x, y, z;
    
    fo(i,1,N) for(int j=i; j<=N; j+=i){
        int k=c/j*j;
        if(c-k<<1>j) k+=j;
        
        int mi=abs(a-i)+abs(b-j)+abs(c-k);
        if(mi<ans) ans=mi, x=i, y=j, z=k;
    }
    cout<<ans<<'\n'<<x<<' '<<y<<' '<<z;
}
