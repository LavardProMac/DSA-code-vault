// Rolling hash O(N+Q)

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=1e5+1;
const int B=311, M=1e9+7;

string s;
ll h[N], hr[N], pw[N];

inline ll get(int l, int r){
    return (h[r]-h[l-1]*pw[r-l+1]%M+M)%M;
}

inline ll getr(int l, int r){
    return (hr[l]-hr[r+1]*pw[r-l+1]%M+M)%M;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int q, l, r; cin>>s>>q;
    int n=s.size(); s=' '+s; pw[0]=1;
    
    fo(i,1,n) pw[i]=pw[i-1]*B%M,
        h[i]=(h[i-1]*B+s[i])%M;

    for(int i=n; i; --i)
        hr[i]=(hr[i+1]*B+s[i])%M;

    while(q--) cin>>l>>r, 
        cout<<(get(l, r)==getr(l, r)? 
               "YES\n":"NO\n");
}
