#include<bits/stdc++.h>
typedef long long ll;
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=2e5+5;
ll sf[N], pf[N];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("C.inp", "r", stdin);
    freopen("C.out", "w", stdout);
    
    string t, s; int n; cin>>t>>n;
    int c=0, m=t.size(); ll ans=0;

    fo(i,1,n){
        cin>>s; int l=s.size();

        if(l>=m) fo(j,0,l-m){
            bool ok=1;
            
            fo(k,0,m-1)
                if(s[j+k]!=t[k]){
                    ok=0; break;
                }
            if(ok) ++c;
        }
        fo(k,1,m-1) if(l>=k){
            bool ok=1;
            
            fo(j,0,k-1)
                if(s[l-k+j]!=t[j]){
                    ok=0; break;
                }
            if(ok) ++sf[k];
            ok=1;
            
            fo(j,0,k-1)
                if(s[j]!=t[m-k+j]){
                    ok=0; break;
                }
            if(ok) ++pf[k];
        }
    }
    fo(k,1,m-1) ans+=sf[k]*pf[m-k];
    cout<<ans+2ll*c*n;
}
